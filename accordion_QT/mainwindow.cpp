
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "section.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Section* section = new Section(ui->centralWidget, "Section", 300);
    //section->setTitle("jjjj");
    ui->centralWidget->layout()->addWidget(section);
    ui->setct->setTitle("secton2");
    ui->setct->setDuration(300);

    auto* anyLayout = new QVBoxLayout();
    anyLayout->addWidget(new QLabel("Some Text in Section", section));
    anyLayout->addWidget(new QPushButton("Button in Section", section));
    anyLayout->addWidget(new QPushButton("hi", section));
    anyLayout->addWidget(new QComboBox());


    auto* x = new QVBoxLayout();
    x->addWidget(new QLabel("Some Text in Section", ui->setct));
    x->addWidget(new QPushButton("Button in Section", ui->setct));
    x->addWidget(new QPushButton("hi", ui->setct));
    x->addWidget(new QComboBox());



    section->setContentLayout(*anyLayout);
    ui->setct->setContentLayout(*x);
}

MainWindow::~MainWindow()
{
    delete ui;
}
