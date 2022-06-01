#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button_ui.h"
#include <button_Events.h>
#include <QQmlContext>
#include <QApplication>
#include <QtWebEngine>
#include <TreeViewModel.h>
#include "QDebug"
#include <combo_box_events.h>
#include <tree_view_events.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button *button_event=new button;
    combo_box_Events *combo_event = new combo_box_Events;
    tree_view_events *tree_event = new tree_view_events();

    qmlRegisterType<button_UI >("contrl_struct",1,0,"Button_UI");

    button_UI *button_ui=new button_UI;
    button_event->set_but_ui(button_ui);

    //modify button ui
//    button_ui->btn_1_wth(300);
//    button_ui->btn_1_hght(60);
//    button_ui->btn_1_bckg_colr("green");
//    button_ui->btn_1_border_col("red");
//    button_ui->btn_1_border_wth(12);
//    button_ui->btn_1_txt_press("gfsgsd");
//    button_ui->btn_1_txt_release("24352");
//    button_ui->btn_1_txt_col("blue");
//    button_ui->btn_1_txt_siz(7);
//    button_ui->btn_1_shadow_rad(5);
//    button_ui->btn_1_shadow_sam(11);
//    button_ui->btn_1_shadow_col("yellow");



    //tree view model class
    TreeViewModel *mymodel=new TreeViewModel;


    qml =new QQuickView(QUrl(QLatin1String("qrc:/main.qml")));

    //send treeview model class to qml
    qml->engine()->rootContext()->setContextProperty("mymodel", mymodel);

    //send button event class to qml
    qml->engine()->rootContext()->setContextProperty("button_wid", button_event);

    //send button ui class to qml
    qml->engine()->rootContext()->setContextProperty("button_ui", button_ui);

    //send combobox event class to qml
    qml->engine()->rootContext()->setContextProperty("comboEvent",combo_event);

    //send treeview event class to qml
    qml->engine()->rootContext()->setContextProperty("treeEvent",tree_event);

    widget = QWidget::createWindowContainer(qml);
    ui->verticalLayout->addWidget(widget);




}

MainWindow::~MainWindow()
{
    delete ui;
}

