#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/res/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMainMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playMusic_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMusic);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);
}

void MainWindow::on_playFilm_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageFilm);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);
}


void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_mainpageButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMainMenu);
}

void MainWindow::on_exitButton_2_clicked()
{
    close();
}
