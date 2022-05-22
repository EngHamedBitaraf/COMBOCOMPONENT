#include "button_Events.h"
#include "QDebug"
#include "button_ui.h"


button::button(QObject *parent) : QObject(parent)
{

}

void button::onClick_More()
{
    button_UI *button_ui = new button_UI;
    qDebug() <<"qml button_More clicked";
    button_ui->btn_1_bckg_colr("red");

}


void button::onClick_Less()
{
    qDebug() <<"qml button_Less clicked";

}

void button::onHover_In()
{
     qDebug() <<"Hover In btn_1";
}

void button::onHover_Out()
{
    qDebug() <<"Hover Out btn_1";
}
