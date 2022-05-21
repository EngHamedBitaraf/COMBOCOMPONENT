#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>

class button : public QObject
{
    Q_OBJECT
public:
    explicit button(QObject *parent = nullptr);

signals:

public slots:
    void onClick_More();
    void onClick_Less();
    void onHover_In();
    void onHover_Out();
};

#endif // BUTTON_H
