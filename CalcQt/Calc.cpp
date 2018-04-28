#include "calcwidget.h"
#include "ui_calcwidget.h"
#include <QMessageBox>
#include <calc.h>
#include <QDebug>
#include <QKeyEvent>

CalcWidget::CalcWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalcWidget)
{
    ui->setupUi(this);
    {
        connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(Clicked_Arephmetick_Symbol()));
        connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Clicked_Arephmetick_Symbol()));
        connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(Clicked_Arephmetick_Symbol()));
        connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(Clicked_Arephmetick_Symbol()));
    }
}
int clickedCount = 1;
Calc calc;

CalcWidget::~CalcWidget()
{
    delete ui;
}

void CalcWidget::keyPressEvent(QKeyEvent *event)
{
    bool ok;
    event->text().toInt(&ok);
    if(ok && (event->text() != PLUS && event->text() != MINUS && event->text() != MUL && event->text() != DIV))
    {
        qDebug() << "ok";
        if(ui->label->text() == "0")
        {
            ui->label->setText(event->text());
        }
        else
        {
            ui->label->setText(ui->label->text() + event->text());
        }
    }
    else if(!ok &&! (event->text() != PLUS && event->text() != MINUS && event->text() != MUL && event->text() != DIV))
    {
        qDebug() << "!ok";
        QString l = ui->label_2->text();
        int len = l.length();
        if(!ui->label_2->text().endsWith("+") && !ui->label_2->text().endsWith("-") && !ui->label_2->text().endsWith("÷") && !ui->label_2->text().endsWith("*"))
        {
            QString str;
            QString text = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
            bool b = text.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
            str = (b ? ui->label_2->text() + "(" + text + ")" : ui->label_2->text()  + text);
            ui->label_2->setText(str + event->text());
            ui->label->setText("0");
        }
        else
        {
            QString label;
            for(int i = 0; i < len;i++)
            {
                label.append(ui->label_2->text()[i]);
            }
            QString str;
            QString text = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
            bool b = text.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
            str = (b ? ui->label_2->text() + "(" + text + ")" : ui->label_2->text()  + text);
            if(clickedCount % 2 == 0 || ++clickedCount % 2 == 0)
            {
                ui->label_2->setText(QString::number(calc.StartAnalize_GetResult(str.replace("÷","/"))) + event->text());
            }
            else
            {
                ui->label_2->setText(str + event->text());
            }
            ui->label->setText("0");
        }
        clickedCount++;
    }
}

void CalcWidget::ButtonClicked()
{
    QPushButton* clicked = (QPushButton*)sender();
    if(ui->label->text() == "0")
    {
        ui->label->setText(clicked->text());
    }
    else
    {
        ui->label->setText(ui->label->text() + clicked->text());
    }
}

void CalcWidget::on_Clear_clicked()
{
    ui->label->setText("0");
    clickedCount = 1;
    ui->label_2->setText("");
}

void CalcWidget::Clicked_Arephmetick_Symbol()
{
    qDebug() << clickedCount;
    QPushButton* clicked = (QPushButton*)sender();
    QString l = ui->label_2->text();
    int len = l.length();
    if(!ui->label_2->text().endsWith("+") && !ui->label_2->text().endsWith("-") && !ui->label_2->text().endsWith("÷") && !ui->label_2->text().endsWith("*"))
    {
        QString str;
        QString text = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
        bool b = text.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
        str = (b ? ui->label_2->text() + "(" + text + ")" : ui->label_2->text()  + text);
            ui->label_2->setText(str + clicked->text());
        ui->label->setText("0");
    }
    else
    {
        QString label;
        for(int i = 0; i < len;i++)
        {
            label.append(ui->label_2->text()[i]);
        }
        QString str;
        QString text = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
        bool b = text.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
        str = (b ? ui->label_2->text() + "(" + text + ")" : ui->label_2->text()  + text);
        if(clickedCount % 2 == 0 || ++clickedCount % 2 == 0)
            ui->label_2->setText(QString::number(calc.StartAnalize_GetResult(str.replace("÷","/"))) + clicked->text());
        else
            ui->label_2->setText(str + clicked->text());
        ui->label->setText("0");
    }
    clickedCount++;
    qDebug() << clickedCount;
}

void CalcWidget::on_GetResult_Button_clicked()
{
    if(ui->label->text() == "0" && ui->label_2->text() == "")
        return;
    if(ui->label_2->text() == "" && ui->label->text() != "0")
    {
        Calc calc;
        ui->label->setText(QString::number(calc.GetResult(0, ui->label->text().toDouble(), '+')));
    }
    else
    {
        QString str;
        QString label = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
        bool b = label.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
        str = (b ? ui->label_2->text() + "(" + label + ")" : ui->label_2->text()  + label);
        str = str.replace("÷", "/");
        ui->label->setText(QString::number(calc.StartAnalize_GetResult(str)));
        ui->label_2->setText("");
    }
}

void CalcWidget::on_pushButton_14_clicked()
{
    double num = ui->label->text().toDouble();
    ui->label->setText(QString::number(num * -1, 'g', 10));
}

void CalcWidget::on_pushButton_Point_clicked()
{
    if(!ui->label->text().contains("."))
        ui->label->setText(ui->label->text() + ".");
}


void CalcWidget::on_pushButton_16_clicked()
{
    ui->label->setText(QString::number(ui->label->text().toDouble() / 100));
}

void CalcWidget::on_pushButton_17_clicked()
{
    if(ui->label_2->text().endsWith("+") || ui->label_2->text().endsWith("-") || ui->label_2->text().endsWith("/") || ui->label_2->text().endsWith("*") || (ui->label->text() == "0"))
    {
        if(ui->label->text() == "0")
             ui->label->setText("3.1415");
        else
            ui->label->setText(ui->label->text() + "3.1415");
    }
}

