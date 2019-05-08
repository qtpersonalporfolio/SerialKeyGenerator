#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonGenerateKey_clicked()
{
    genKey = new MenuGenKey(this);
    genKey->show();
}

void MainWindow::on_ButtonExit_clicked()
{
    MainWindow::close();
}
