#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test: public QObject
{
    Q_OBJECT
public:
    explicit Test(int,int, QObject *parent = 0);
    ~Test();
private:
    int X,Y;
private slots:
    void correct_output();// проверяем корректность вывода в виджет данных
};

#endif // TEST_H
