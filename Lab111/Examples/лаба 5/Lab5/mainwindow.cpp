#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <cmath>

double num_first=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_div->setCheckable(true);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_change,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton  *button = (QPushButton*)sender();//ссылка на нажатую кнопку

    double numbers;
    numbers = (ui->result_show->text().toDouble());

    try
    {
        if(!( ui->result_show->text().size()>14) && !(ui->result_show->text().contains("e")))
        {
            QString new_label;
            if(ui->result_show->text().contains(".") && button->text()=="0")
            {
                new_label=ui->result_show->text() + button ->text();
            }
            else
            {
                numbers=(ui->result_show->text() + button ->text()).toDouble();
                new_label=QString::number(numbers,'g',10);
            }
            ui->result_show->setText(new_label);
        }
        else
        {
            throw numbers;
        }
    }
    catch (double a)
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!!\nЧисло слишком длинное");
        msgBox.exec();
    }

}

void MainWindow::operations()
{
    QPushButton  *button = (QPushButton*)sender();//ссылка на нажатую кнопку

    double numbers;
    QString new_label;

    if(button->text() ==  "+/-")
    {
        numbers=(ui->result_show->text()).toDouble();
        numbers= numbers*(-1);
        new_label=QString::number(numbers,'g',15);
        ui->result_show->setText(new_label);
    }
    else if(button->text()=="%")
    {
        numbers=(ui->result_show->text()).toDouble();
        numbers= numbers*(0.01);
        new_label=QString::number(numbers,'g',15);
        ui->result_show->setText(new_label);
    }

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::math_operations()
{

    QPushButton  *button = (QPushButton*)sender();//ссылка на нажатую кнопку

    num_first=ui->result_show->text().toDouble();

    ui->result_show->setText("");
    ui->EnterLabel->setText("");

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_div->setChecked(false);

    ui->EnterLabel->setText(QString::number(num_first,'g',15)+button->text());
    button->setChecked(true);

}

void MainWindow::on_pushButton_clear_clicked()
{

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_div->setChecked(false);

    ui->EnterLabel->setText("");

    ui->result_show->setText("0");

}
void MainWindow::on_pushButton_res_clicked()
{
    try
    {
        double labelNumber,num_second;
        QString new_label;

        num_second=ui->result_show->text().toDouble();

        if(ui->pushButton_plus->isChecked())
        {
            labelNumber=num_first+num_second;
            new_label=QString::number(labelNumber,'g',15);
            ui->result_show->setText(new_label);
            ui->pushButton_plus->setChecked(false);
        }
        else if(ui->pushButton_minus->isChecked())
        {

            labelNumber=num_first-num_second;
            new_label=QString::number(labelNumber,'g',15);
            ui->result_show->setText(new_label);
            ui->pushButton_minus->setChecked(false);

        }
        else if(ui->pushButton_mult->isChecked())
        {
            labelNumber=num_first*num_second;
            new_label=QString::number(labelNumber,'g',15);
            ui->result_show->setText(new_label);
            ui->pushButton_mult->setChecked(false);
        }
        else if(ui->pushButton_div->isChecked())
        {
            if(num_second==0)
            {
                throw 2;
                ui->result_show->setText("Error");
            }
            else
            {
                labelNumber=num_first/num_second;
                new_label=QString::number(labelNumber,'g',15);
                ui->result_show->setText(new_label);
            }
            ui->pushButton_div->setChecked(false);
        }
        ui->EnterLabel->setText(ui->EnterLabel->text()+QString::number(num_second,'g',15));
    }
    catch (int a)
    {
        switch(a)
        {
            case 1:
            {
                QMessageBox msgBox;
                msgBox.setText("Ошибка!!");
                msgBox.exec();
                break;
            }
            case 2:
            {
                QMessageBox msgBox;
                msgBox.setText("Ошибка!!\nНельзя делить на ноль");
                msgBox.exec();
                break;
            }
        }

    }


}

void MainWindow::on_pushButton_ln_clicked()
{
    double number=ui->result_show->text().toDouble();
    number=log(number);
    QString new_label=QString::number(number,'g',15);
    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_arcsin_clicked()
{
     double number=ui->result_show->text().toDouble();
     number=asin(number);
     QString new_label=QString::number(number,'g',15);
     ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    double number=ui->result_show->text().toDouble();
    number=sqrt(number);
    QString new_label=QString::number(number,'g',15);
    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_pow_clicked()
{
    try
    {
        double number=ui->result_show->text().toDouble();
        number=pow(number,2.0);
        QString new_label=QString::number(number,'g',15);
        if(new_label.contains("inf"))
        {
            throw number;
        }
        else
        {
            ui->result_show->setText(new_label);
        }
    }
    catch (double a)
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка вычисления числа\nПолученное число слишком большое");
        msgBox.exec();
    }
}
