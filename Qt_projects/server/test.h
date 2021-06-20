#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "database.h"

class Test : public QObject
    {
        Q_OBJECT
    public:
        explicit Test(database, QString, QObject *parent = 0);
        ~Test();
    private:
        QString compare;
        database *DB;

    private slots:
        void Check_BD();// проверяем корректность считывания данных из базы данных
};

#endif // TEST_H
