#include "combo_box_events.h"
#include "QDebug"
combo_box_Events::combo_box_Events(QObject *parent) : QObject(parent)
{

}

void combo_box_Events::onActivated(QString currentText)
{
    qDebug() << currentText;
}

void combo_box_Events::onHighlightedIndexChanged()
{

}

void combo_box_Events::onCurrentIndexChanged()
{

}

void combo_box_Events::onCurrentTextChanged()
{

}
