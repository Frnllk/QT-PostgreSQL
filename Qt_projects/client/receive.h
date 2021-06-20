#ifndef RECEIVE_H
#define RECEIVE_H

#include <QObject>
#include <QUdpSocket>

#include <memory>

class Receive: public QObject
{
    Q_OBJECT
public:
    explicit Receive(QObject *parent = 0);

private:
    QByteArray getPart(const QByteArray message, int part, bool toEnd);
signals:

void Output(QByteArray x,QByteArray y);

public slots:
    void readyRead();

private:
    std::unique_ptr <QUdpSocket> receiver;
    qint16 port = 1010;

};

#endif // RECEIVE_H
