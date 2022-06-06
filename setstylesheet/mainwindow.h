#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>

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
//    void enterEvent(QEvent *event);
//    void leaveEvent(QEvent *event);

private slots:


private:
    Ui::MainWindow *ui;
    QPushButton *abbas = new QPushButton;
    QPushButton *changiz = new QPushButton;
    void click_btn_abb();
    void toggle_btn_cha();

};
#endif // MAINWINDOW_H
