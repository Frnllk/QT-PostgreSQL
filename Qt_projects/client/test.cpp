#include "test.h"
#include <QTest>

Test::Test(int x, int y,QObject *parent) :
    QObject(parent)
{
    X=x;
    Y=y;
}

Test::~Test()
{

}

void Test::correct_output()
{
    QCOMPARE(X, 12);
    QCOMPARE(Y, 13);
}
