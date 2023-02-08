#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include <piperead.h>
#include <pipewrite.h>
#include <QCommandLineParser>

#include <QDir>
#include <QDebug>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    signals:

       void sendMessage(QString);


    public:
        MainWindow(QString rd, QString wt, QWidget *parent = nullptr);
        ~MainWindow();

    public slots:


    private slots:
        void getReaded();
        void StartReadThread();

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

    private:
        PIPERead *pipeRead;
        PIPEWrite *pipeWrite;


        int fd1[2], fd2[2];

        QThread *read_thread = new QThread;
        QThread *write_thread= new QThread;
        Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
