#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QGraphicsColorizeEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    abbas = new QPushButton(this);
    abbas->setGeometry(50,100,150,50);
    abbas->setText("Hi");

    sample = new QComboBox(this);
    sample->setGeometry(600,100,150,35);
    for(int i = 0; i < 10; i++)
        {
           sample->addItem("item " + QString::number(i));
        }


    changiz = new QPushButton(this);
    changiz->setGeometry(350,100,150,50);
    changiz->setText("Bye");

    changiz->setCheckable(true);

    //create theme for stylesheet
    QString theme = "*[mandatoryField=\"true\"] { background-color: gray ; border: 3px solid black }";

    connect(abbas, &QPushButton::clicked, this, &MainWindow::click_btn_abb);
    connect(changiz, &QPushButton::toggled, this, &MainWindow::toggle_btn_cha);


    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(7);
    effect->setOffset(4,4);
    effect->setColor("#3DB74E");
    changiz->setGraphicsEffect(effect);


    //temporary set stylesheet

    changiz->setStyleSheet(QString::fromUtf8("QPushButton{"
                                             "  background: #ffffff;\n"
                                             "  border: 1px solid #3db74e;\n"
                                             "  color: #3DB74E;\n"
                                             "  border-radius: 7px;\n"
                                             "}\n"
                                             "QPushButton:hover{ \n"
                                             "  color: white;\n"
                                             "  border: 2px solid white;\n"
                                             "  background: #3db74e;\n"
                                             "}\n"
                                             ));


    sample->setStyleSheet(QString::fromUtf8("QComboBox{"
        "subcontrol-origin: padding;\n"
        "subcontrol-position: top right;\n"
        "selection-background-color: #111;\n"
        "selection-color: yellow;\n"
        "color: white;\n"
        "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
        "border-style: solid;\n"
        "border: 1px solid #1e1e1e;\n"
        "border-radius: 5;\n"
        "padding: 1px 0px 1px 20px;\n"

    "}\n"


    "QComboBox:hover, QPushButton:hover{\n"
        "border: 2px solid yellow;\n"
        "color: white;\n"
    "}\n"

    "QComboBox:editable {\n"
        "background: red;\n"
        "color: pink;\n"
    "}\n"

    "QComboBox:on{\n"
        "padding-top: 0px;\n"
        "padding-left: 0px;\n"
        "color: red;\n"
        "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
        "selection-background-color: blue;\n"
    "}\n"

    "QComboBox:!on{\n"
        "color: white;\n"
        "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #666, stop: 0.1 #555, stop: 0.5 #555, stop: 0.9 #444, stop: 1 #333);\n"
    "}\n"



    "QComboBox::drop-down{\n"
         "subcontrol-origin: padding;\n"
         "subcontrol-position: top right;\n"
         "width: 15px;\n"
         "color: red;\n"
         "border-left-width: 0px;\n"
         "border-left-color: darkgray;\n"
         "border-left-style: solid;\n"
         "border-top-right-radius: 3px;\n"
         "border-bottom-right-radius: 3px;\n"
         "padding-left: 10px;\n"

     "}\n"

     "QComboBox QAbstractItemView {\n"
     "border: 2px solid darkgray;\n"
     "selection-background-color: lightgray;\n"
     "background-color:gray;\n"
     "}\n"

    "QComboBox::down-arrow, QSpinBox::down-arrow, QTimeEdit::down-arrow, QDateEdit::down-arrow{\n"
         "image: qrc:/kindpng.png;\n"
         "width: 7px;\n"
         "height: 5px;\n"
    "}\n"

      ));


    //using theme in stylesheet

    //        changiz->setProperty("mandatoryField",true);
    //        changiz->setStyleSheet(theme);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_btn_abb()
{
    QGraphicsColorizeEffect *eEffect = new QGraphicsColorizeEffect(abbas);
    abbas->setGraphicsEffect(eEffect);
    QPropertyAnimation *paAnimation = new QPropertyAnimation(eEffect,"color");
    paAnimation->setStartValue(QColor(Qt::blue));
    paAnimation->setEndValue(QColor(Qt::red));
    paAnimation->setEasingCurve(QEasingCurve::InOutCubic);
    paAnimation->setDuration(2000);
    paAnimation->start();
    //paAnimation->setDirection(QPropertyAnimation::Forward);
    paAnimation->setLoopCount(4);
}

void MainWindow::toggle_btn_cha()
{
    //    QGraphicsDropShadowEffect* esffect = new QGraphicsDropShadowEffect();
    //    esffect->setBlurRadius(4);
    //    esffect->setOffset(4,4);
    //    esffect->setColor("red");
    //    changiz->setGraphicsEffect(esffect);
}

