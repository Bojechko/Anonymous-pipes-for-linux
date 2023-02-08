#include "mainwindow.h"


#include <QApplication>
#include <QCommandLineParser>

QString parserLineRead ;
QString parserLineWrite ;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption runnable_option(QStringList() << "w", "write", "w");
    parser.addOption(runnable_option);
    QCommandLineOption runnable_option_2(QStringList() << "r", "read", "r");
    parser.addOption(runnable_option);
    parser.addOption(runnable_option_2);
    parser.process(a);

    if (parser.isSet(runnable_option)){
        parserLineRead = parser.value("r");
        parserLineWrite = parser.value("w");
    } else {
        parserLineRead = "";
        parserLineWrite = "";
    }


    const QStringList args = parser.positionalArguments();

    MainWindow w(parserLineRead, parserLineWrite);

    w.show();
    return a.exec();
}
