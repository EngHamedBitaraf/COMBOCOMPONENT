#ifndef SEC_H
#define SEC_H

#include <QWidget>
#include <QQuickView>
namespace Ui {
class sec;
}

class sec : public QWidget
{
    Q_OBJECT

public:
    explicit sec(QWidget *parent = nullptr);
    ~sec();

private:
    Ui::sec *ui;
    QQuickView* qml;
    QWidget *widget;
};

#endif // SEC_H
