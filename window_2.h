#ifndef WINDOW_2_H
#define WINDOW_2_H

#include <QWidget>
#include <QtGui>
#include <QMainWindow>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickView>
#include <QWidget>
namespace Ui {
class window_2;
}

class window_2 : public QWidget
{
    Q_OBJECT

public:
    explicit window_2(QWidget *parent = nullptr);
    ~window_2();

private:
    Ui::window_2 *ui;
    void ReadDBandDisplay();
    QQuickView* qml;
    QWidget *wid;
};

#endif // WINDOW_2_H
