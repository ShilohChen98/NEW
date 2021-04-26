#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QKeyEvent>
#include <QCloseEvent>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form_1 =new Form1();



/**
    //QlineEdit
    QString str = ui->lineEdit->text();//获取内容
    qDebug() << str;
    //设置内容
    ui->lineEdit->setText("nihaoya");

    //设置内容显示间隔
    ui->lineEdit->setTextMargins(15,0,0,0);//单位是像素点

    //设置内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);

    //
    QStringList list;
    list << "hello" << "how are u" <<"hi" << "hehe";
    QCompleter *com = new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    //QLabel
    ui->label->setText("文字显示");

     //设置动画
    QMovie *mymovie = new QMovie("C:/Users/Administrator/Downloads/20210317_212150.gif");
    ui->label_3->setMovie(mymovie);
    mymovie->start();
    ui->label_3->setScaledContents(true);

    //设置html
    ui->label_4->setOpenExternalLinks(true);


    //进度条

     for (int i=0;i<1001;i++)
     {


      ui->progressBar->setMinimum(0);
      ui->progressBar->setMaximum(0);
      ui->progressBar->setValue(i);



     }

**/


ui->label->setPixmap(QPixmap(":/image/武科大炼铁研究所-2.png"));
ui->label->setScaledContents(true);

ui->lineEdit->setEchoMode(QLineEdit::Password);





}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString str = ui->lineEdit->text();
    if(str =="123"){

      window()->close();

    //  QWidget *new_win =new QWidget();
    //  new_win->setWindowTitle("Cooling stave system");
    //  new_win->show();
      form_1->setWindowTitle("Cooling stave system");
      form_1->show();



    }
    else {
       QMessageBox::warning(this,"error","请输入正确的密码");
    }

}


void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if(e->key() == 16777220 || 16777221   )
    {
        MainWindow::on_pushButton_clicked();
    }

}
void Form1::closeEvent(QCloseEvent *ev)
{

    int ret = QMessageBox::question(this,"question","是否关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接收事件，事件就不会再往下传递
        ev->accept();

    }
    else {
        //不关闭窗口
        //忽略事件，事件继续往父组件传递
        ev->ignore();
         }
}













