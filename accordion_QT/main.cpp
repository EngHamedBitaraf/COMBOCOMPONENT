
#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyleSheet("QPushButton {background: #ffffff;\n"
                         "color: white;\n"
                         "border: 1px solid white;\n"
                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
                         "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
                         "border-radius: 7px;\n"
                         "}\n"
                         "QPushButton:hover{\n"
                         "color: black;\n"
                         "border: 2px solid black;\n"
                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
                         "stop:0 rgba(161, 161, 156, 255)"
                         "stop:0.18 rgba(161, 161, 156, 255)"
                         "stop:0.36 rgba(177, 177, 172, 255)"
                         "stop:0.54 rgba(193, 192, 187, 255)"
                         "stop:0.72 rgba(208, 208, 202, 255)"
                         "stop:0.90 rgba(224, 224, 213, 255)"
                         "stop:1 rgba(240, 239, 226, 255));\n"
                         "}"
                        "QComboBox {"
                        "border: 1px solid white;"
                        "border-radius: 5px;"
                        "padding: 1px 18px 1px 3px;"
                        "min-width: 6em;"
                    "}\n"

                    "QComboBox:editable {\n"
                        "background: white;\n"
                    "}\n"

                    "QComboBox:hover{\n"
                        "border: 2px solid black;\n"
                        "}"

                    "QComboBox:!editable, QComboBox::drop-down:editable {\n"
                         "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                                                "stop: 0 #833ab4, stop: 0.5 #fd1d1d,"
                                                "stop: 1.0 #fcb045);\n"
                    "}\n"


                    "QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
                        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
                                                "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
                    "}\n"

                    "QComboBox:on {\n"
                       "padding-top: 3px;\n"
                       "padding-left: 4px;\n"
                    "}\n"

                    "QComboBox::drop-down {\n"
                        "subcontrol-origin: padding;\n"
                        "subcontrol-position: top right;\n"
                        "width: 24px;\n"

                        "border-left-width: 1px;\n"
                        "border-left-color: darkgray;\n"
                        "border-left-style: solid;\n"
                        "border-top-right-radius: 3px;\n"
                    "}\n"

                    "QComboBox::down-arrow {\n"
                        "image: url(:/icons8-double-down-64.png);\n"
                        "width: 36px;n"

                    "}\n"

                    "QComboBox::down-arrow:on {\n"
                        "top: 1px;\n"
                        "left: 1px;\n"

                    "}\n"
                        );


    MainWindow w;
    w.show();

    return a.exec();
}
