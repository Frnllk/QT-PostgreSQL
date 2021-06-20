#ifndef SEND_H
#define SEND_H

#include <QObject>
#include <QUdpSocket>

#include <memory>

class Send: public QObject
{
    Q_OBJECT
public:
    explicit Send(QObject *parent = 0);

    void send(std::string &);

signals:

private:
    std::unique_ptr <QUdpSocket> sender;
    qint16 port = 1010;
};


#endif // SEND_H
