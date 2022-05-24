#ifndef COMBO_BOX_EVENTS_H
#define COMBO_BOX_EVENTS_H

#include <QObject>

class combo_box_Events : public QObject
{
    Q_OBJECT
public:
    explicit combo_box_Events(QObject *parent = nullptr);

signals:

public slots:
    void onActivated(QString currentText);
    void onHighlightedIndexChanged();
    void onCurrentIndexChanged();
    void onCurrentTextChanged();
};

#endif // COMBO_BOX_EVENTS_H
