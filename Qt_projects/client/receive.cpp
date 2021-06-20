#include "receive.h"
#include <iterator>
#include <regex>
#include <QDataStream>

Receive::Receive(QObject *parent) : QObject(parent)
{
    qDebug("Constructor for RECEIVER");

    receiver = std::make_unique <QUdpSocket> (this);
    connect(receiver.get(), SIGNAL(readyRead()), this, SLOT(readyRead()));
    if (!receiver->bind(port, QUdpSocket::ShareAddress))// .....................   обработка исключения
 ;
    // port = 1010, установлен по умолчанию в заголовочном файле

}

void Receive::readyRead()
{
    QByteArray buffer;
    buffer.resize(receiver->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    receiver->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    // читаем из сокета

    qDebug() << "ReadyRead-Receiver! Message: " << buffer;
    qDebug() << getPart(buffer,2,false);
    qDebug() << getPart(buffer,5,false);

    emit Output(getPart(buffer,2,false),getPart(buffer,5,false));

}

QByteArray Receive::getPart(const QByteArray message, int part, bool toEnd)//Функция возвращающая необходимую часть сообщения
 {

    int characters(toEnd ? -1 : message.indexOf(' ', part) - part);

    return message.mid(part, characters);
 }
