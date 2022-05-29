#ifndef BUTTON_H
#define BUTTON_H
#include "button_ui.h"
#include <QObject>

class button : public QObject
{
    Q_OBJECT
public:
    explicit button(QObject *parent = nullptr);
    void set_but_ui(button_UI *button_ui);

signals:

public slots:
    void onClick_More();
    void onClick_Less();
    void onHover_In();
    void onHover_Out();
private:
    button_UI *button_ui;
};

#endif // BUTTON_H
