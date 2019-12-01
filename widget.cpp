#include "widget.h"
#include "ui_widget.h"
#include "stdlib.h"
#include "time.h"
#include "Qdebug"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand (time(nullptr));

    secretNumber = rand() % 10 +1;

    qDebug() << "Secret number generated : " << QString::number(secretNumber);

    ui->startOverButton->setDisabled(true);

    ui->messageLabel->setText(" ");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "The guessed number is : " << QString::number(guessNumber);

    if( guessNumber == secretNumber)
    {
        ui->messageLabel->setText("Congrats , number is  "+QString::number(secretNumber));
        ui->startOverButton->setDisabled(false);
        ui->guessButton->setDisabled(true);
    }
    else
    {
        if(guessNumber < secretNumber)
            ui->messageLabel->setText("The number is greater than that ");

        if(guessNumber > secretNumber)
            ui->messageLabel->setText("The number is lower than that ");
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->startOverButton->setDisabled(true);
    ui->guessButton->setDisabled(false);
    ui->spinBox->setValue(1);

    secretNumber = rand() % 10 + 1;
    ui->messageLabel->setText(" ");

}
