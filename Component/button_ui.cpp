#include "button_ui.h"

button_UI::button_UI(QObject *parent) : QObject(parent)
{

}

void button_UI::btn_1_wth(qint16 btn_wth)
{
    btn_1_width = btn_wth;
}

void button_UI::btn_1_hght(qint16 btn_hgt)
{
    btn_1_height = btn_hgt;
}


void button_UI::btn_1_bckg_colr(QString colr)
{
    btn_1_bckg_colrr = colr;

}

void button_UI::btn_1_border_wth(qint8 bord_wth)
{
    btn_1_border_width = bord_wth;
}

void button_UI::btn_1_border_col(QString bord_clor)
{
    btn_1_border_colr = bord_clor;
}

void button_UI::btn_1_txt_press(QString txt)
{
    btn_1_txt_prs = txt;
}

void button_UI::btn_1_txt_release(QString txt)
{
    btn_1_txt_rel = txt;
}


void button_UI::btn_1_txt_col(QString txt_colr)
{
    btn_1_txt_colr = txt_colr;
}

void button_UI::btn_1_txt_siz(qint8 txt_size)
{
    btn_1_txt_size = txt_size;
}

void button_UI::btn_1_shadow_rad(qint8 radius)
{
    btn_1_shadow_radius = radius;
}

void button_UI::btn_1_shadow_sam(qint8 sample)
{
    btn_1_shadow_sample = sample;
}

void button_UI::btn_1_shadow_col(QString color)
{
    btn_1_shadow_color = color;
}






qint16 button_UI::get_btn_1_wth()
{
    return btn_1_width;
}

qint16 button_UI::get_btn_1_hght()
{
    return btn_1_height;
}

QString button_UI::get_btn_1_bckg_colr(){
    return btn_1_bckg_colrr;
}

qint8 button_UI::get_btn_1_border_wth()
{
    return btn_1_border_width;
}

QString button_UI::get_btn_1_border_col()
{
    return btn_1_border_colr;
}

QString button_UI::get_btn_1_txt_press()
{
    return btn_1_txt_prs;
}

QString button_UI::get_btn_1_txt_release()
{
    return btn_1_txt_rel;
}

QString button_UI::get_btn_1_txt_col()
{
    return btn_1_txt_colr;
}

qint8 button_UI::get_btn_1_txt_siz()
{
    return btn_1_txt_size;
}

qint8 button_UI::get_btn_1_shadow_rad()
{
    return btn_1_shadow_radius;
}

qint8 button_UI::get_btn_1_shadow_sam()
{
    return btn_1_shadow_sample;
}

QString button_UI::get_btn_1_shadow_col()
{
    return btn_1_shadow_color;
}






