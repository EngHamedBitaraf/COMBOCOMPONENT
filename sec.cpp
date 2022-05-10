#include "sec.h"
#include "ui_sec.h"

sec::sec(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sec)
{
    ui->setupUi(this);
    qml =new QQuickView(QUrl(QLatin1String("qrc:/Search_Box.qml")));
    widget = QWidget::createWindowContainer(qml);
    ui->verticalLayout->addWidget(widget);
}

sec::~sec()
{
    delete ui;
}
