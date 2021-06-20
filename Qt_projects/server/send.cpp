#include "send.h"
#include <memory>

Send::Send(QObject *parent) : QObject(parent)
{
    qDebug("Constructor for SENDER");

    sender = std::make_unique <QUdpSocket> (this);
    sender->bind(QHostAddress::LocalHost, port);

}

void Send::send(std::string &message)
{
    qDebug("Now we send message");
    QByteArray Data;               // Заполняем byte-array с нашим сообщением
    Data.append(message.c_str());

    sender->writeDatagram(Data, QHostAddress::Broadcast, port); // Отправляем с помощью сокета
}


