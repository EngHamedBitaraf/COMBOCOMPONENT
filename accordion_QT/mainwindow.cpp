#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "section.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Section* section = new Section(ui->centralWidget, "Section_2", 300);
    //section->setTitle("jjjj");
    ui->centralWidget->layout()->addWidget(section);

    ui->setct->setTitle("secton_1");
    ui->setct->setDuration(300);

    auto* anyLayout = new QVBoxLayout();
    anyLayout->addWidget(new QLabel("Some Text in Section 2", section));
    anyLayout->addWidget(new QPushButton("Button in Section 2", section));
    anyLayout->addWidget(new QPushButton("bye", section));
    anyLayout->addWidget(new QComboBox());

    Section* y = new Section(ui->centralWidget, "Section_3", 300);
    ui->centralWidget->layout()->addWidget(y);

    auto* mos = new QVBoxLayout();
    mos->addWidget(new QLabel("Some Text in Section 3", y));
    mos->addWidget(new QPushButton("Button in Section 3", y));
    mos->addWidget(new QPushButton("lie", y));
    mos->addWidget(new QComboBox());



    QComboBox *abbas = new QComboBox;
    abbas->addItem("test_1");
    abbas->addItem("test_2");
    abbas->setMaximumWidth(100);



    QPushButton *mosi = new QPushButton;
    mosi->setText("hi");
    mosi->setStyleSheet("QPushButton {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 51, 102, 255), "
                        "stop:0.18 rgba(43, 54, 56, 255),"
                        "stop:0.36 rgba(56, 68, 69, 255)"
                        "stop:0.54 rgba(68, 81, 82, 255)"
                        "stop:0.72 rgba(81, 95, 95, 255)"
                        "stop:0.90 rgba(93, 108, 108, 255)"
                        "stop:1 rgba(106, 122, 121, 255));}");
    mosi->setMaximumWidth(200);


    auto* x = new QVBoxLayout();
    x->addWidget(new QLabel("Some Text in Section 1", ui->setct));
    x->addWidget(new QPushButton("Button in Section 1", ui->setct));
    x->addWidget(mosi);
    x->addWidget(new QPushButton("my", ui->setct));
    x->addWidget(new QPushButton("why", ui->setct));
    x->addWidget(abbas);



    section->setContentLayout(*anyLayout);
    ui->setct->setContentLayout(*x);
    y->setContentLayout(*mos);
}

MainWindow::~MainWindow()
{
    delete ui;
}
