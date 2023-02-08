#include "piperead.h"


PIPERead::PIPERead()
{
    connect(this, &PIPERead::readWork, this, &PIPERead::loopSlot);
}

void PIPERead::loopSlot(){
    qDebug("loop start read" );


    char arr1[80];



    qDebug("otkryl canal read");

    read(dr, arr1, sizeof(arr1));

    printf("User2: %s\n", arr1);

    getWrite = arr1;

    emit finished();

    emit readWork();
}

QString PIPERead::getMessage(){
    qDebug() << getWrite;
    QString temp =getWrite;
    getWrite ="";
    return temp;
}

void PIPERead::setDescriptor(int dr){

    this->dr = dr;
}

void PIPERead::readSlot()
{
    emit readWork();
}
