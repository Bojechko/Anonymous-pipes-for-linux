#ifndef PIPEREAD_H
#define PIPEREAD_H


#include <QProcess>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include <QDir>
#include <QDebug>
#include <QThread>



class PIPERead : public QObject
{
    Q_OBJECT
    public:
        PIPERead();

       // ~PIPERead();

        QString getMessage();
        void setDescriptor(int dr);

    public slots:

        void readSlot();
        void loopSlot();


    signals:
        void readSignal();
        void readed();
        void finished();
        void readWork();


    private:
        int dr;

        QString getWrite;
};

#endif // PIPEREAD_H
