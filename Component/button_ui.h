#ifndef BUTTON_UI_H
#define BUTTON_UI_H

#include <QObject>

class button_UI : public QObject
{
    Q_OBJECT
public:

//    QString c = "fu";
//    struct ret_border{
//        qint8 bord_wth;
//        QString bord_clor;
//    };
    //ret_border b;
    explicit button_UI(QObject *parent = nullptr);





private:

    qint16 btn_1_width = 200;
    qint16 btn_1_height = 50;

    QString btn_1_bckg_colrr = "white";

    qint8 btn_1_border_width = 2;
    QString btn_1_border_colr = "#1aba1a";

    QString btn_1_txt_prs = "More Detail";
    QString btn_1_txt_rel = "Less Detail";

    QString btn_1_txt_colr = "#1aba1a";
    qint8 btn_1_txt_size = 20;

    qint8 btn_1_shadow_radius = 8;
    qint8 btn_1_shadow_sample = 17;
    QString btn_1_shadow_color = "#1aba1a";


signals:

public slots:
    //set_func
    void btn_1_wth (qint16 btn_wth);
    void btn_1_hght (qint16 btn_hgt);
    void btn_1_bckg_colr(QString colr);
    void btn_1_border_wth(qint8 bord_wth);
    void btn_1_border_col(QString bord_clor);
    void btn_1_txt_press(QString txt);
    void btn_1_txt_release(QString txt);
    void btn_1_txt_col(QString txt_colr);
    void btn_1_txt_siz(qint8 txt_size);
    void btn_1_shadow_rad(qint8 radius);
    void btn_1_shadow_sam(qint8 sample);
    void btn_1_shadow_col(QString color);
    //get_func
    qint16 get_btn_1_wth ();
    qint16 get_btn_1_hght ();
    QString get_btn_1_bckg_colr();
    qint8 get_btn_1_border_wth();
    QString get_btn_1_border_col();
    QString get_btn_1_txt_press();
    QString get_btn_1_txt_release();
    QString get_btn_1_txt_col();
    qint8 get_btn_1_txt_siz();
    qint8 get_btn_1_shadow_rad();
    qint8 get_btn_1_shadow_sam();
    QString get_btn_1_shadow_col();

};

#endif // BUTTON_UI_H
