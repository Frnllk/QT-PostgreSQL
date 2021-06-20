#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "message.h"
#include "QSqlError"
#include <QSqlRecord>
#include "QString"

class database
{
public:
    database();
    bool Check_open();
    QSqlDatabase db;
    void read();
    QString Current_x_y(QString);
    QString Full_message;
};

#endif // DATABASE_H
