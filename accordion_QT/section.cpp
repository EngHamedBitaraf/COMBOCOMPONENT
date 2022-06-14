
#include <QPropertyAnimation>

#include "section.h"
#include <QDebug>
    Section::Section(QWidget* parent, const QString& title, const int animationDuration)
        : QWidget(parent), animationDuration(animationDuration)
    {
        toggleButton = new QToolButton(this);
        headerLine = new QFrame(this);
        toggleAnimation = new QParallelAnimationGroup(this);
        contentArea = new QScrollArea(this);
        //contentArea->setStyleSheet("QScrollArea {border: none;}");
        contentArea->setStyleSheet("QScrollArea {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 51, 102, 255), "
                                   "stop:0.18 rgba(23, 73, 120, 255),"
                                   "stop:0.36 rgba(45, 97, 138, 255)"
                                   "stop:0.54 rgba(70, 118, 155, 255)"
                                   "stop:0.72 rgba(94, 140, 173, 255)"
                                   "stop:0.90 rgba(94, 140, 173, 255)"
                                   "stop:1 rgba(117, 162, 191, 255));}");
        //contentArea->setMaximumWidth(300);
        mainLayout = new QGridLayout(this);
        toggleButton->setStyleSheet("QToolButton {border: none; color: #2F5F8A;}");
        toggleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toggleButton->setArrowType(Qt::ArrowType::RightArrow);
        setWindowTitle(title);
        toggleButton->setText(windowTitle());
        toggleButton->setCheckable(true);
        toggleButton->setChecked(false);

        //headerLine->setFrameShape(QFrame::HLine);
        //headerLine->setFrameShadow(QFrame::Sunken);
        headerLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

        contentArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        // start out collapsed
        contentArea->setMaximumHeight(0);
        contentArea->setMinimumHeight(0);



        // let the entire widget grow and shrink with its content
        toggleAnimation->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
        toggleAnimation->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
        toggleAnimation->addAnimation(new QPropertyAnimation(contentArea, "maximumHeight"));

        mainLayout->setVerticalSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        int row = 0;
        mainLayout->addWidget(toggleButton, row, 0, 1, 1, Qt::AlignLeft);
        mainLayout->addWidget(headerLine, row++, 2, 1, 1);
        mainLayout->addWidget(contentArea, row, 0, 1, 3);
        setLayout(mainLayout);

        connect(toggleButton, &QToolButton::toggled, this, &Section::toggle);
    }

    void Section::toggle(bool expanded)
    {
        toggleButton->setArrowType(expanded ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        toggleAnimation->setDirection(expanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
        toggleAnimation->start();
        
        this->isExpanded = expanded;
        
        qDebug() << "MV: toggle: isExpanded " << isExpanded;
    }

    void Section::setContentLayout(QLayout& contentLayout)
    {
        delete contentArea->layout();
        contentArea->setLayout(&contentLayout);
        collapsedHeight = sizeHint().height() - contentArea->maximumHeight();
        
        updateHeights();
    }
    
    void Section::setTitle(QString title)
    {
        setWindowTitle(title);
        toggleButton->setText(windowTitle());
    }

    void Section::setDuration(int animationDuration)
    {
        this->animationDuration = animationDuration;
    }
    
    void Section::updateHeights()
    {
        int contentHeight = contentArea->layout()->sizeHint().height();

        for (int i = 0; i < toggleAnimation->animationCount() - 1; ++i)
        {
            QPropertyAnimation* SectionAnimation = static_cast<QPropertyAnimation *>(toggleAnimation->animationAt(i));
            SectionAnimation->setDuration(animationDuration);
            SectionAnimation->setStartValue(collapsedHeight);
            SectionAnimation->setEndValue(collapsedHeight + contentHeight);
        }

        QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *>(toggleAnimation->animationAt(toggleAnimation->animationCount() - 1));
        contentAnimation->setDuration(animationDuration);
        contentAnimation->setStartValue(0);
        contentAnimation->setEndValue(contentHeight);
        
        toggleAnimation->setDirection(isExpanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
        toggleAnimation->start();
    }
