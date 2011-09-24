#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QDialog>

namespace Ui {
    class Client;
}

class Client : public QDialog {
    Q_OBJECT
public:
    Client();
    ~Client();
    void sendClient(QString, int, int);

private:
    Ui::Client *ui;
    QTcpSocket tcpSocket;
    quint64 nextBlockSize;
signals:
    void createNewField(QList<QList<int> > mat, int,QStringList,QList<QPair<int, int> > );
    void doClick(QString, int,int);

private slots:
    void on_pushButton_clicked();
    void updateInfo();
    void connected();
    void displayError(QAbstractSocket::SocketError socketError);
};

#endif // CLIENT_H
