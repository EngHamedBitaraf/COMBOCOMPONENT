#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qml =new QQuickView(QUrl(QLatin1String("qrc:/Btn_More_Detail.qml")));
    widget = QWidget::createWindowContainer(qml);
    ui->verticalLayout->addWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

