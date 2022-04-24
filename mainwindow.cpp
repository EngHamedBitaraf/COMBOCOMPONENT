#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window_2.h"
#include "QQmlContext"
#include "QQmlEngine"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window_2 *abbas = new window_2;

    qml_quickwidget = new QQuickWidget(this);
    qml_quickwidget->setSource(QUrl("qrc:/main.qml"));
    qml_quickwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->horizontalLayout->addWidget(qml_quickwidget);

    qml_quickwidget->engine()->rootContext()->setContextProperty("window_2",abbas);








}

MainWindow::~MainWindow()
{
    delete ui;
}




