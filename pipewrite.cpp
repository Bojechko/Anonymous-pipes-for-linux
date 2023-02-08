#include "pipewrite.h"

PIPEWrite::PIPEWrite()
{
    connect(this, &PIPEWrite::writeWork, this, &PIPEWrite::loopSlot);
}

void PIPEWrite::loopSlot(){

    qDebug("loop start write" );


    // FIFO file path

    char str[80] = "" ;

    memcpy(str, toWrite.toStdString().c_str(), toWrite.size());

    qDebug("otkryl canal write");

    write(dw, str, strlen(str)+1);

    qDebug("zakryl canal write");
    //sleep(100);


}

void PIPEWrite::setMessage(QString str){

    toWrite = str;
    qDebug()<<str;
    emit writeWork();

}



void PIPEWrite::writeSlot()
{
    emit writeWork();
}

void PIPEWrite::setDescriptor(int dw){
    this->dw = dw;
}

