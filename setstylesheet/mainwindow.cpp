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

    changiz = new QPushButton(this);
    changiz->setGeometry(350,100,150,50);
    changiz->setText("Bye");

    changiz->setCheckable(true);

    connect(abbas, &QPushButton::clicked, this, &MainWindow::click_btn_abb);
    connect(changiz, &QPushButton::toggled, this, &MainWindow::toggle_btn_cha);


    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(4);
    effect->setOffset(4,4);
    effect->setColor("#3DB74E");
    changiz->setGraphicsEffect(effect);

    changiz->setStyleSheet(QString::fromUtf8("QPushButton{"
                                             "  position: relative;\n"
                                             "  font-weight: 100;\n"
                                             "  background: #ffffff;\n"
                                             "  border: 1px solid #3db74e;\n"
                                             "  text-decoration: none;\n"
                                             "  color: #3DB74E;\n"
                                             "  padding: 15px 20px;\n"
                                             "}\n"
                                             "QPushButton:hover{ \n"
                                             "  color: white;\n"
                                             "  border: 1px solid white;\n"
                                             "  background: #3db74e;\n"
                                             "}"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_btn_abb()
{
    QGraphicsColorizeEffect *eEffect= new QGraphicsColorizeEffect(abbas);
    abbas->setGraphicsEffect(eEffect);
    QPropertyAnimation *paAnimation = new QPropertyAnimation(eEffect,"color");
    paAnimation->setStartValue(QColor(Qt::blue));
    paAnimation->setEndValue(QColor(Qt::red));
    paAnimation->setEasingCurve(QEasingCurve::InOutCubic);
    paAnimation->setDuration(2000);
    paAnimation->start();
}

void MainWindow::toggle_btn_cha()
{
//    QGraphicsDropShadowEffect* esffect = new QGraphicsDropShadowEffect();
//    esffect->setBlurRadius(4);
//    esffect->setOffset(4,4);
//    esffect->setColor("red");
//    changiz->setGraphicsEffect(esffect);
}
