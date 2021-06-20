#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "receive.h"
#include <math.h>
#include <QTest>
#include "test.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание Таблицы

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//запрет на редактирование в окне
    ui-> tableWidget->setRowCount(current+1); // указываем количество строк
    ui-> tableWidget->setColumnCount(3); // указываем количество столбцов

    //форматирование таблицы
    ui->tableWidget->setHorizontalHeaderLabels({"x","y","distance"});
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //создаем соединение для вывода данных при их получении
    Receive *obj = new Receive();
    connect(obj, SIGNAL(Output(QByteArray,QByteArray)), this, SLOT(get(QByteArray,QByteArray)));
}


MainWindow::~MainWindow()
{
    delete ui;
    delete item_x;
    delete item_y;
    delete item_sum;
}

void MainWindow::get(QByteArray x, QByteArray y)
{
    ui-> tableWidget->setRowCount(current+1); // устанавливем корректное значение строк
    item_x = new QTableWidgetItem(); // выделяем память под ячейки
    item_y = new QTableWidgetItem();
    item_sum = new QTableWidgetItem();

    item_x->setText(QString(x).arg(1).arg(1)); // вставляем значение х
    ui->tableWidget->setItem(current, 0, item_x); // вставляем ячейку

    item_y->setText(QString(y).arg(1).arg(1)); // вставляем значение y
    ui->tableWidget->setItem(current, 1, item_y); // вставляем ячейку

    //первая ячейка дистанции не должна быть заполнена
    if(first_message){
        item_sum->setText(QString("-").arg(1).arg(1));
        ui->tableWidget->setItem(current, 2, item_sum);
        first_message=0;
        qDebug() << QTest::qExec(new Test(ui->tableWidget->item(current,0)->text().toInt(),ui->tableWidget->item(current,1)->text().toInt())); // Запуск unit теста
    }else {
        a=(ui->tableWidget->item(current,0)->text().toInt()) - (ui->tableWidget->item(current-1,0)->text().toInt());
        b=(ui->tableWidget->item(current,1)->text().toInt()) - (ui->tableWidget->item(current-1,1)->text().toInt());
        sum =sqrt(pow((a),2)+pow((b),2)); // считаем расстояние
        item_sum->setData(Qt::DisplayRole,sum); // вставляем расстояние
        ui->tableWidget->setItem(current, 2, item_sum); // вставляем ячейку
    }
    current++; // переменная отвечающая за строку

}
