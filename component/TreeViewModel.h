#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H


#include <QStandardItemModel>


class TreeViewModel :public QStandardItemModel
{
    Q_OBJECT
public:
    TreeViewModel(QObject *parent = nullptr);
};

#endif // TREE_VIEW_MODEL_H
