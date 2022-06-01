#ifndef TREE_VIEW_EVENTS_H
#define TREE_VIEW_EVENTS_H

#include <QObject>

class tree_view_events : public QObject
{
    Q_OBJECT
public:
    explicit tree_view_events(QObject *parent = nullptr);
private:
QString treeview_current_txt="defult";

signals:

public slots:
    void onClicked(QString text);
    void onCurrentIndexChanged();
    void onRootIndexChanged();

};

#endif // TREE_VIEW_EVENTS_H
