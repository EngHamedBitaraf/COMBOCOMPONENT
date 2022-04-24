#include "new.h"
#include "ui_new.h"

new::new(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new)
{
    ui->setupUi(this);
}

new::~new()
{
delete ui;
}
