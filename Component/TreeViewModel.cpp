#include "TreeViewModel.h"
#include <QStandardItem>


TreeViewModel::TreeViewModel(QObject *parent)
    :QStandardItemModel{parent}
{
    setColumnCount(1);
    QStandardItem *rootItem = invisibleRootItem();

    QStandardItem *group1 = new QStandardItem;
    QStandardItem *group2 = new QStandardItem;
    QStandardItem *group3 = new QStandardItem;

    QStandardItem *value1 = new QStandardItem;
    QStandardItem *value2 = new QStandardItem;
    QStandardItem *value3 = new QStandardItem;
    QStandardItem *value4 = new QStandardItem;
    QStandardItem *value5 = new QStandardItem;
    QStandardItem *value6 = new QStandardItem;
    QStandardItem *value7 = new QStandardItem;

    QStandardItem *item0 = new QStandardItem;


    group1->setText("group 1");
    group2->setText("group 2");
    group3->setText("group 3");

    value1->setText("value 1");
    value2->setText("value 2");
    value3->setText("value 3");
    value4->setText("value 4");
    value5->setText("value 5");
    value6->setText("value 6");
    value7->setText("value 7");

    item0->setText("item 0");

    rootItem->appendRow(group1);
    rootItem->appendRow(group2);
    rootItem->appendRow(group3);

    group1->appendRow(value1);
    group1->appendRow(value2);
    group1->appendRow(value3);

    group2->appendRow(value4);
    group2->appendRow(value5);

    group3->appendRow(value6);
    group3->appendRow(value7);

    value1->appendRow(item0);


}
