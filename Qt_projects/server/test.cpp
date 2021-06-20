#include "test.h"
#include <QTest>
#include "database.h"

Test::Test(database this_DB, QString cur, QObject *parent) :
    QObject(parent)
{
    compare = cur;
    DB=&this_DB;
}

Test::~Test()
{
    delete DB;
}

void Test::Check_BD()
{
    QCOMPARE(DB->Current_x_y(compare), QString("12 13"
                                              "12 25"
                                              "14 25"
                                              "19 75"
                                              "28 96"
                                              "54 68"
                                              "55 58"
                                              "68 72"
                                              "76 85"));
}
