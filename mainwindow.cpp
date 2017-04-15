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

    Game game;
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

void MainWindow::on_statButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);

    ui->statBrowser->clear();
    QSqlQuery query=game.getStats();
    while (query.next())
        {
        QString login = query.value(0).toString();
        QString music_score = query.value(1).toString();
        QString film_score = query.value(2).toString();
        ui->statBrowser->insertPlainText(login+" "+music_score+" "+film_score+"\n");
        }
}

void MainWindow::on_statButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);
}
