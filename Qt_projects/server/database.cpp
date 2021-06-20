#include "database.h"
#include <QSqlDatabase>

database::database()
{
    db= QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
       db.setHostName("localhost");
       db.setUserName("postgres");
       db.setPassword("0000");

}

bool database::Check_open()
{
    if (!db.open())
    {
        return false;
    }
    return true;
}

void database::read()
{
    QSqlQuery query(db);//начинаем работать с бд

    query.prepare("SELECT * FROM public.\"Points\"  ORDER BY x ASC, y ASC "); //формируем запрос

    if( !query.exec() ) { // ловим ошибки

            qDebug() << db.lastError().text();

       }

    Message new_message; // создаем экземпляр сообщения

    QSqlRecord rec = query.record();
    const int get_X = rec.indexOf( "x" );
    const int get_Y = rec.indexOf( "y" );

    while( query.next() ) { // просматриваем всю таблицу и отправляем данные клиенту

            QString data = query.value(get_X).toString();
            data.append(" ");
            data.append(query.value(get_Y).toString());
            qDebug() << data;
            std::string std_data =data.toStdString();
            new_message.send(std_data);
            Full_message.append(data);

       }
}

QString database::Current_x_y(QString Cur_xy)
{
    return Cur_xy;
}
