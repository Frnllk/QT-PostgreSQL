#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

#include <send.h>

class Message: public QObject
{

    Q_OBJECT
public:
    explicit Message(QObject *parent = 0);
     ~Message();

    void send(std::string &sended_msg);

private:

        Send sender;
};

#endif // MESSAGE_H
