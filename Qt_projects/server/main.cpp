#include <QCoreApplication>
#include "database.h"
#include <QTest>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    database Point = *new database();
    qDebug() << "Success in establishing a connection to the database: " << Point.Check_open() ;
    Point.read();
    QTest::qExec(new Test(Point,Point.Full_message)); // Запуск unit теста
    return a.exec();
}
