#ifndef BUTTON_UI_H
#define BUTTON_UI_H

#include <QObject>

class button_UI : public QObject
{
    Q_OBJECT
public:

    struct ret_border{
        qint8 bord_wth;
        QString bord_clor;
    };

    explicit button_UI(QObject *parent = nullptr);
    QString Btn_1_bckg_colr(QString colr);
    ret_border Btn_1_border(qint8 bord_wth,QString bord_clor);
    QString Btn_1_txt(QString txt,QString txt_colr,qint8 txt_size);
    QString Btn_1_shadow(qint8 radius,qint8 sample,QString color);




private:

    QString btn_1_bckg_colr = "white";

    qint8 btn_1_border_width = 2;
    QString btn_1_border_colr = "#1aba1a";

    QString btn_1_txt = "More Detail";
    QString btn_1_txt_colr = "#1aba1a";
    qint8 btn_1_txt_size = 20;

    qint8 btn_1_shadow_radius = 8;
    qint8 btn_1_shadow_sample = 17;
    QString btn_1_shadow_color = "#1aba1a";

signals:

public slots:
};

#endif // BUTTON_UI_H
