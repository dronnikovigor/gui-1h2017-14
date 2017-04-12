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

void MainWindow::on_playMusic_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMusic);
}

void MainWindow::on_playFilm_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageFilm);
}


void MainWindow::on_exitOnMain_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::on_exitGame_triggered()
{
    close();
}
