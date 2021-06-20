#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTableWidgetItem"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QTableWidget * tableWidget ;

private:
    Ui::MainWindow *ui;
    int current = 0;
    double sum =0,a,b;
    bool first_message=1;
    QTableWidgetItem *item_x;
    QTableWidgetItem *item_y;
    QTableWidgetItem *item_sum;


 public slots:

    void get (QByteArray,QByteArray);

};

#endif // MAINWINDOW_H
