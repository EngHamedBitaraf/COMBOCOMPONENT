#include "button_Events.h"
#include "QDebug"

button::button(QObject *parent) : QObject(parent)
{

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
     qDebug() <<"Hover In btn_1";
}

void button::onHover_Out()
{
    qDebug() <<"Hover Out btn_1";
}
