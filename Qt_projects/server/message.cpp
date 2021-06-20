#include "message.h"

#include <iostream>

Message::Message(QObject *parent) : QObject(parent)
{
}

Message::~Message()
{
    qDebug("Messege-DESTRUCTOR\n");
}

void Message::send(std::string &sended_msg)
// Получаем сообщение и вызываем sender
{
    std::string message ;
    message += ": ";
    message += sended_msg;

    sender.send(message);
}
