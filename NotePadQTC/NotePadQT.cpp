#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

bool isChanged = false;
QString pathtosave = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(on_Exit()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(on_Open()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(on_save()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(on_save_as()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(on_NewFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *evnt)
{
    if(pathtosave != "" && isChanged)
    {
        int result = QMessageBox::question(this,"Exit", "Do you want to save changes in " + pathtosave + " ?", QMessageBox::Abort | QMessageBox::Yes | QMessageBox::No);
        if(result == QMessageBox::Yes)
        {
            QFile file(pathtosave);
            file.open(QIODevice::WriteOnly);
            QByteArray array;
            array.append(ui->textEdit->toPlainText());
            file.write(array);
        }
        else if (result == QMessageBox::Abort)
        {
            evnt->ignore();
        }
    }
}


void MainWindow::on_Exit()
{
    if(pathtosave != "" && isChanged)
    {
        int result = QMessageBox::question(this,"Exit", "Do you want to save changes in " + pathtosave + " ?", QMessageBox::Abort | QMessageBox::Yes | QMessageBox::No);
        if(result == QMessageBox::Abort)
        {
            return;
        }
        else if(result == QMessageBox::Yes)
        {
            QFile file(pathtosave);
            file.open(QIODevice::WriteOnly);
            QByteArray array;
            array.append(ui->textEdit->toPlainText());
            file.write(array);
        }
    }
    QApplication::quit();
}


void MainWindow::on_Open()
{
    QString temp = "";
    if(pathtosave != "" && isChanged)
    {
        temp = pathtosave;
        int result = QMessageBox::question(this,"Exit", "Do you want to save changes in " + pathtosave + " ?", QMessageBox::Abort | QMessageBox::Yes | QMessageBox::No);
        if(result == 262144)
        {
            return;
        }
        else if(result == 16384)
        {
            on_save();
        }
    }
    QFileDialog* dialog = new QFileDialog();
    dialog->setParent(this);
    pathtosave = dialog->getOpenFileName(this, tr("Opening file"), "/home/");
    if(pathtosave.isEmpty())
    {
        return;
    }
    QFile file(pathtosave);
    if(!file.open(QIODevice::ReadOnly) && pathtosave != "")
    {
        QMessageBox::warning(this,"Error","Sorry, Error to open file\n");
        pathtosave = temp;
        return;
    }
    QByteArray a = file.readAll();
    QString text = "";
    text.append(a);
    ui->textEdit->setText(text);
    isChanged = false;
    ui->textEdit->setVisible(true);
    ui->statusBar->showMessage("File: " + pathtosave);
}



void MainWindow::on_save()
{
    if(pathtosave != "")
    {
        ui->statusBar->showMessage("Saving...");
        QFile file(pathtosave);
        file.open(QIODevice::WriteOnly);
        QByteArray array;
        array.append(ui->textEdit->toPlainText());
        file.write(array);
        ui->statusBar->showMessage("Saved.");
        isChanged = false;
    }
    else
    {
        on_save_as();
    }
}

void MainWindow::on_save_as()
{
    if(ui->textEdit->isVisible())
    {
        QFileDialog* dialog = new QFileDialog();
        dialog->setParent(this);
        QString s = dialog->getSaveFileName(this,"Save as","/home/");
        if(s.isEmpty())
            return;
        QFile file(s);
        file.open(QIODevice::WriteOnly);
        QByteArray array;
        array.append(ui->textEdit->toPlainText());
        file.write(array);
        ui->statusBar->showMessage("Saved.");
        isChanged = false;
        if(pathtosave == "")
            pathtosave = s;
    }
}

void MainWindow::on_NewFile()
{
    if(pathtosave != "" && isChanged)
    {
        int result = QMessageBox::question(this,"Exit", "Do you want to save changes in " + pathtosave + " ?", QMessageBox::Abort | QMessageBox::Yes | QMessageBox::No);
        if(result == 262144)
        {
            return;
        }
        else if(result == 16384)
        {
            on_save();
        }
    }
    ui->textEdit->setVisible(true);
    ui->textEdit->setText("");
    pathtosave = "";
    isChanged = false;
}

void MainWindow::on_textEdit_textChanged()
{
    isChanged = true;
}
