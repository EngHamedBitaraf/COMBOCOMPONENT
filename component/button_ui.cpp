#include "button_ui.h"

button_UI::button_UI(QObject *parent) : QObject(parent)
{

}

QString button_UI::Btn_1_bckg_colr(QString colr)
{
    btn_1_bckg_colr = colr;

    return btn_1_bckg_colr;
}

button_UI::ret_border button_UI::Btn_1_border(qint8 bord_wth, QString bord_clor)
{
    ret_border retBorder;
    retBorder.bord_wth = bord_wth;
    retBorder.bord_clor = bord_clor;
    return retBorder;

}

QString button_UI::Btn_1_txt(QString txt, QString txt_colr, qint8 txt_size)
{
    btn_1_txt = txt;
    btn_1_txt_colr = txt_colr;
    btn_1_txt_size = txt_size;
}

QString button_UI::Btn_1_shadow(qint8 radius, qint8 sample, QString color)
{
    btn_1_shadow_radius = radius;
    btn_1_shadow_sample = sample;
    btn_1_shadow_color = color;
}



