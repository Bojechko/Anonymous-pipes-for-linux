#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString rd, QString wt, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pipeRead = new PIPERead();
    pipeWrite = new PIPEWrite();

    if ((wt != "") && (rd != "")){
        pipeRead->setDescriptor(rd.toInt());
        pipeWrite->setDescriptor(wt.toInt());
    } else {
        pipe(fd1);
        pipe(fd2);
        pipeRead->setDescriptor(fd1[0]);
        pipeWrite->setDescriptor(fd2[1]);
    }

    StartReadThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartReadThread(){
    pipeRead->moveToThread(read_thread);
    connect(read_thread, SIGNAL(started()), pipeRead, SLOT(readSlot()));
    connect(pipeRead, SIGNAL(finished()), this, SLOT(getReaded()));

    read_thread->start();

}

void MainWindow::getReaded()
{
    ui->label_output->setText(pipeRead->getMessage());
}


void MainWindow::on_pushButton_clicked()
{
    QProcess process;
    QString s = "";

    process.startDetached( QApplication::applicationDirPath() + "/PIPETest", QStringList()
                           << "-w" << s.number(fd1[1])
                           << "-r" << s.number(fd2[0]));

    //Если просто start, то займет родительский процесс
    //process.start( QApplication::applicationDirPath() + "/sao-mp/program", QStringList() << "");
    if( !process.waitForStarted() || !process.waitForFinished() ) {
        return;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString str =ui->lineEdit->text();

    pipeWrite->setMessage(str);

    pipeWrite->moveToThread(write_thread);

    connect(write_thread, SIGNAL(started()), pipeWrite, SLOT(writeSlot()));
    connect(pipeWrite, SIGNAL(finished()), write_thread, SLOT(terminate()));


    write_thread->start();

}

