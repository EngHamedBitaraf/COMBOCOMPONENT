#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include<QComboBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    QPushButton *abbas = new QPushButton;
    QPushButton *changiz = new QPushButton;
    QComboBox *sample = new QComboBox;

    void click_btn_abb();
    void toggle_btn_cha();


};
#endif // MAINWINDOW_H
