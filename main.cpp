#include <QApplication>
#include "mainwidget.h"
#include "mainwindow.h"
#include <QTextCodec>
#include <QPlastiqueStyle>

int main(int argc,char**envp)
{
    QApplication app(argc,envp);
    Q_INIT_RESOURCE(resource);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    app.setStyle(new QPlastiqueStyle());
    MainWindow window;
    window.show();
    return app.exec();
}
