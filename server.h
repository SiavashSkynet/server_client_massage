#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QIODevice>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class server; }
QT_END_NAMESPACE

class server : public QMainWindow
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();
    QString my_string;


signals:

public slots:
    QByteArray newConnection();
    void readyRead();

private:
    QList<QTcpSocket*>  _sockets;
    QTcpServer *server_handler;
    Ui::server *ui;
};
#endif // SERVER_H
