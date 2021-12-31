#include "server.h"
#include "ui_server.h"

static QString needded;
QTcpSocket *my_tcp = new QTcpSocket;

server::server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::server)
{
//    ui->setupUi(this);
    server_handler = new QTcpServer(this);

    connect(server_handler,SIGNAL(newConnection()),this,SLOT(newConnection()),Qt::QueuedConnection);

    if (!server_handler->listen(QHostAddress::Any,1234))
    {
        qDebug() << "server could not start!";
    }
    else
    {
        qDebug() << "server work!";
    }
}

server::~server()
{
    delete ui;
}

QByteArray server::newConnection()
{
    QTcpSocket *_socket = nullptr;
    QByteArray data = _socket->readAll();

    qDebug()<<"new Conncetion is comming ...";


   QString SUserID;
   QString SDevice_ID;
   QString dataRec= QString(data);

   qDebug()<<data;
}

void server::readyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
   for (QTcpSocket* socket : _sockets) {
       if (socket != sender)
            socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": " + datas.toStdString()));

   }
    QString str = QString::fromStdString(datas.toStdString());
//    QString my_string;
    my_string += str;
    qDebug()<<"This is what we recieved";
    qDebug()<<my_string;
    str.replace("\r\n","");
    needded = str;

}
