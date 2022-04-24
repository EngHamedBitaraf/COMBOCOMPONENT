#include "window_2.h"
#include "ui_window_2.h"
#include "QComboBox"
#include "Qt"
#include "QQmlContext"
#include "QQmlEngine"

window_2::window_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_2)

{
    ui->setupUi(this);
    ReadDBandDisplay();




    qml =new QQuickView(QUrl(QLatin1String("qrc:/Main_Back_G.qml")));
    wid = QWidget::createWindowContainer(qml);
    ui->verticalLayout_6->addWidget(wid);





}

window_2::~window_2()
{
    delete ui;


}

void window_2::ReadDBandDisplay(){
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QPSQL","DBconnection");
    dataBase.setHostName("localhost");
    dataBase.setDatabaseName("test");
    dataBase.setUserName("postgres");
    dataBase.setHostName("localhost");
    dataBase.setPassword("qazwsx");


    if (!dataBase.open()){
        qDebug() <<"Database open Error" <<dataBase.lastError().text();
        return;
    }

    QSqlQuery query(dataBase);
    QString str = "SELECT * from test";

    if (!query.exec(str)){
        qDebug() <<"Query execution failed";
        return;
    }
    ui->tableWidget->setColumnCount(4);
    QStringList labels;
    labels << "ID" << "Name" << "Last_Name" << "Gender";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    int rowCount = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(rowCount);

        QTableWidgetItem *ID = new QTableWidgetItem;
        QTableWidgetItem *Name = new QTableWidgetItem;
        QTableWidgetItem *Last_Name = new QTableWidgetItem;
        QTableWidgetItem *Gender = new QTableWidgetItem;

        ID->setText(query.value(0).toString());
        Name->setText(query.value(1).toString());
        Last_Name->setText(query.value(2).toString());
        Gender->setText(query.value(3).toString());

        QComboBox* GendCBox = new QComboBox();

        GendCBox->addItem(Gender->text());
        GendCBox->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(46, 47, 64, 249), stop:1 rgba(255, 255, 255, 255));");


        if(Gender->text()=="Male   "){
            GendCBox->addItem("Female");
        }
            else{
                GendCBox->addItem("Male");


        }


        ui->tableWidget->setCellWidget(rowCount,3,GendCBox);


        ui->tableWidget->setItem(rowCount,0,ID);
        ui->tableWidget->setItem(rowCount,1,Name);
        ui->tableWidget->setItem(rowCount,2,Last_Name);
        //ui->tableWidget->setItem(rowCount,3,Gender);
        rowCount++;

    }

        dataBase.close();


}




