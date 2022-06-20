#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "section.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTreeView>
#include <TreeViewModel.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString btn_theme = "*[mandatoryField=\"true\"] {background: #ffffff;\n"
//                            "color: white;\n"
//                            "border: 1px solid white;\n"
//                            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
//                            "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
//                            "border-radius: 7px;\n"
//                            "}\n"
//                            "QPushButton:hover{\n"
//                            "color: black;\n"
//                            "border: 2px solid black;\n"
//                            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
//                            "stop:0 rgba(161, 161, 156, 255)"
//                            "stop:0.18 rgba(161, 161, 156, 255)"
//                            "stop:0.36 rgba(177, 177, 172, 255)"
//                            "stop:0.54 rgba(193, 192, 187, 255)"
//                            "stop:0.72 rgba(208, 208, 202, 255)"
//                            "stop:0.90 rgba(224, 224, 213, 255)"
//                            "stop:1 rgba(240, 239, 226, 255));\n"
//                            "}";

    Section* section = new Section(ui->centralWidget, "Section_2", 300);
    //section->setTitle("jjjj");
    ui->centralWidget->layout()->addWidget(section);

    ui->setct->setTitle("Secton_1");
    ui->setct->setDuration(300);

    QLabel *label_2 = new QLabel;
    label_2->setText("some text in section 2");
    label_2->setStyleSheet("QLabel{color: white;}");
    auto* anyLayout = new QVBoxLayout();
    anyLayout->addWidget(label_2);
    anyLayout->addWidget(new QPushButton("Button in Section 2", section));
    anyLayout->addWidget(new QPushButton("bye", section));
    anyLayout->addWidget(new QComboBox());

    Section* y = new Section(ui->centralWidget, "Section_3", 300);
    ui->centralWidget->layout()->addWidget(y);


    QLabel *label_3 = new QLabel;
    label_3->setText("some text in section 3");
    label_3->setStyleSheet("QLabel{color: white;}");
    auto* mos = new QVBoxLayout();
    mos->addWidget(label_3);
    mos->addWidget(new QPushButton("Button in Section 3", y));
    mos->addWidget(new QPushButton("lie", y));
    mos->addWidget(new QComboBox());



    QComboBox *abbas = new QComboBox;
    abbas->addItem("test_1");
    abbas->addItem("test_2");
    abbas->setMaximumWidth(100);
    abbas->setMinimumHeight(40);


    QLabel *label_1 = new QLabel;
    label_1->setText("some text in section 1");
    label_1->setStyleSheet("QLabel{color: white;}");

    QPushButton *mosi = new QPushButton;

    mosi->setText("hi");
//    mosi->setProperty("mandatoryField",true);
//    mosi->setStyleSheet(btn_theme);
    //mosi->setMaximumWidth(200);
    mosi->setMinimumHeight(40);

    QPushButton *boos = new QPushButton;

    boos->setText("jy");
//    boos->setProperty("mandatoryField",true);
//    boos->setStyleSheet(btn_theme);
    boos->setMinimumHeight(40);

    QPushButton *loos = new QPushButton;

    loos->setText("my");
//    loos->setProperty("mandatoryField",true);
//    loos->setStyleSheet(btn_theme);
    loos->setMinimumHeight(40);

    QTreeView* hey = new QTreeView;
    TreeViewModel* mymodel = new TreeViewModel;
    hey->setModel(mymodel);
    hey->setHeaderHidden(true);
    hey->setMinimumHeight(225);
    hey->setAnimated(true);

    hey->setStyleSheet("QTreeView {\n"
                       "alternate-background-color: yellow;\n"
                       "background-color: gray"
                        "}\n"

                       "QTreeView:item {\n"
                       "border-top-color: transparent;\n"
                       "border-bottom-color: transparent;\n"
                        "}\n"

                       "QTreeView:item:hover {\n"
                       "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
                       "stop:0 rgba(161, 161, 156, 255)"
                       "stop:0.18 rgba(161, 161, 156, 255)"
                       "stop:0.36 rgba(177, 177, 172, 255)"
                       "stop:0.54 rgba(193, 192, 187, 255)"
                       "stop:0.72 rgba(208, 208, 202, 255)"
                       "stop:0.90 rgba(224, 224, 213, 255)"
                       "stop:1 rgba(240, 239, 226, 255));\n"
                       "border: 1px solid #bfcde4;\n"
                        "}\n"

                       "QTreeView:item:selected {\n"
                       "border: 1px solid white;\n"
                        "}\n"

                       "QTreeView:item:selected:active{\n"
                       "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                       "stop: 0 #6ea1f1, stop: 1 #567dbc);\n"
                        "}\n"

                       "QTreeView:item:selected:!active {\n"
                       "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                       "stop: 0 #6b9be8, stop: 1 #577fbf);\n"
                        "}\n"

                         );




    auto* x = new QVBoxLayout();
    x->addWidget(label_1);
    x->addWidget(boos);
    x->addWidget(mosi);
    x->addWidget(loos);
    x->addWidget(abbas);
    x->addWidget(hey);



    section->setContentLayout(*anyLayout);
    ui->setct->setContentLayout(*x);
    y->setContentLayout(*mos);

}

MainWindow::~MainWindow()
{
    delete ui;
}
