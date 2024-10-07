#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdlib.h>
#include <math.h>

char operation = '+';
int answer;
int statment1;
int statment2;
int score = 0;

QString first = QString::number(statment1);
QString second = QString::number(statment2);
QString operation1 = QString(operation);
QString userinput;
QString textscore = QString::number(score);

MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ResetBtn_clicked()
{
    getfact(operation);

}

void MainWindow::getfact(char operation)
{
    switch(operation){

    case '+':

        statment1 = rand() % (10 + 1);
        statment2 = rand() % (10 + 1);

        answer = statment1 + statment2;
        break;

    case '-':

        redosub:
        statment1 = rand() % (10 + 1);
        statment2 = rand() % (10 + 1);

        answer = statment1 - statment2;

        while(answer <= 0)goto redosub;

        break;

    case '*':

        statment1 = rand() % (10 + 1);
        statment2 = rand() % (10 + 1);

        answer = statment1 * statment2;

        break;

    case '/':


        redodiv:
        statment1 = rand() % (10 + 1);
        statment2 = rand() % (10 + 1);

        if(statment1 == 0 || statment2 == 0)goto redodiv;

        answer = statment1 % statment2;

        while(answer <= 0)goto redodiv;

        break;

    default:

        break;

    }

   first = QString::number(statment1);

   second = QString::number(statment2);

   operation1 = QString(operation);

   ui->FirstStatment->setText(first);

   ui->operatoText->setText(operation1);

   ui->SecondStatment->setText(second);

}

void MainWindow::on_SubmitBtn_clicked()
{
    userinput = ui->lineEdit->text();

    if(userinput.toInt() == answer)
    {
        score ++;
    }else score --;

    textscore = QString::number(score);

    ui->scoretext->setText(textscore);

    getfact(operation);


}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //remember that the index is an array
    switch(index)
    {
    case 0:

        operation = '+';

        break;

    case 1:

        operation = '-';

        break;

    case 2:

        operation = '*';

        break;

    case 3:

        operation = '/';

        break;

    }
}

