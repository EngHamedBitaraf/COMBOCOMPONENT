#include "button_Events.h"
#include "QDebug"
#include "button_ui.h"


button::button(QObject *parent) : QObject(parent)
{

}

void button::set_but_ui(button_UI *button_ui)
{
    this->button_ui = button_ui;

}

void button::onClick_More()
{
    qDebug() <<"qml button_More clicked";

}


void button::onClick_Less()
{
    qDebug() <<"qml button_Less clicked";

}

void button::onHover_In()
{
    //button_ui->btn_1_bckg_colr("red");
    qDebug() <<button_ui->get_btn_1_bckg_colr();

}

void button::onHover_Out()
{
    qDebug() <<"Hover Out btn_1";
}
