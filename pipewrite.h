#ifndef PIPEWRITE_H
#define PIPEWRITE_H
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



class PIPEWrite : public QObject
{
    Q_OBJECT
    public:
        PIPEWrite();
        void setDescriptor(int dw);
       // ~PIPEWrite();

    public slots:
        void writeSlot();
        void setMessage(QString);
        void loopSlot();



    signals:
        void writeSignal();
        void finished();


        void writeWork();

    private:

        QString toWrite;
        int dw;
};
#endif // PIPEWRITE_H
