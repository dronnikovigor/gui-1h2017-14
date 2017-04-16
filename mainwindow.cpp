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

void MainWindow::on_statButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);

    statsOut();
}

void MainWindow::on_statButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);

    statsOut();
}

void MainWindow::on_loginButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageLogin);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);
}

void MainWindow::on_loginButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageLogin);
    ui->menuWidget->setCurrentWidget(ui->pageGameOut);
}

void MainWindow::statsOut()
{
    ui->statBrowser->clear();
    QSqlQuery query=game.getStats();

    QString html;
    html = "<table width=\"490\"><tr><td><b>Имя игрока</b></td><td><b>Музыка</b></td><td><b>Фильмы</b></td><td><b>Всего</b></td></tr>";

    while (query.next())
        {
        QString login = query.value(0).toString();
        QString music_score = query.value(1).toString();
        QString film_score = query.value(2).toString();
        int total = music_score.toInt()+film_score.toInt();
        html += "<tr><td>"+login+"</td><td>"+music_score+"</td><td>"+film_score+"</td><td>"+QString::number(total)+"</td></tr>";
        }
    html += "</table>";
    ui->statBrowser->insertHtml(html);
}
