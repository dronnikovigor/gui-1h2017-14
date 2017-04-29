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

    QPixmap bkgnd2(":/images/res/background_login.png");
    bkgnd2 = bkgnd2.scaled(ui->widgetLogin->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd2);
    ui->widgetLogin->setAutoFillBackground(true);
    ui->widgetLogin->setPalette(palette);
    ui->widgetLogin_2->setAutoFillBackground(true);
    ui->widgetLogin_2->setPalette(palette);
    ui->widgetCreators->setAutoFillBackground(true);
    ui->widgetCreators->setPalette(palette);

    setNameAndScore();

    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMenuLogout);

    player = new QMediaPlayer;
    backgroundMusic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playMusic_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMusic);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    game.eraseContent("music");

    updatePlayScreen("music");
}

void MainWindow::on_playFilm_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageFilm);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}

void MainWindow::on_exitButton_2_clicked()
{
    close();
}

void MainWindow::on_exitButton_3_clicked()
{
    close();
}

void MainWindow::on_mainpageButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMain);
    if(game.isLogin()){
        ui->menuWidget->setCurrentWidget(ui->pageMenuLogin);
    }
    else{
        ui->menuWidget->setCurrentWidget(ui->pageMenuLogout);
    }
}

void MainWindow::on_statButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_3_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::statsOut()
{    
    player -> setVolume(30);
    ui->statBrowser->clear();
    QSqlQuery query = game.getStats();

    QString html;
    html = "<table width=\"490\"><tr><td><b>Имя игрока</b></td><td><b>Музыка</b></td>"
           "<td><b>Фильмы</b></td><td><b>Всего</b></td></tr>";

    while (query.next())
        {
        QString login = query.value(0).toString();
        QString music_score = query.value(1).toString();
        QString film_score = query.value(2).toString();
        int total = music_score.toInt() + film_score.toInt();
        html += "<tr><td>" + login + "</td><td>" + music_score + "</td><td>" +
                film_score + "</td><td>" + QString::number(total) + "</td></tr>";
        }
    html += "</table>";
    ui->statBrowser->insertHtml(html);
}

void MainWindow::on_loginButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageLogin);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}

void MainWindow::on_cancelButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMenuLogout);
}

void MainWindow::on_loginButton_3_clicked()
{
    if (ui->username->text() != "" && ui->password->text() != "")
    {
        if (game.login(ui->username->text(), ui->password->text()))
        {
            setNameAndScore();

            ui->gameWidget->setCurrentWidget(ui->pageMain);
            ui->menuWidget->setCurrentWidget(ui->pageMenuLogin);
        }
        else
        {
            ui->label_5->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"
                                 "Неправильный логин и/или пароль!</span></p></body></html>");
        }
    }
    else
    {
        ui->label_5->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"
                             "Все поля должны быть заполнены!</span></p></body></html>");
    }
}

void MainWindow::on_answerButton_1_clicked()
{
    checkAnswer("music", 1);
}


void MainWindow::on_answerButton_2_clicked()
{
    checkAnswer("music", 2);
}

void MainWindow::on_answerButton_3_clicked()
{
    checkAnswer("music", 3);
}

void MainWindow::on_answerButton_4_clicked()
{
    checkAnswer("music", 4);
}

void MainWindow::updatePlayScreen(QString type)
{
    if(!game.playGame(type)){
        player -> setVolume(30);
        on_statButton_clicked();
    }
    else
    {
        if (type=="music"){
            player -> setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath() +
                                                   "/../../gui-1h2017-14/res/music/" +
                                                   game.getRightAnswerId(type) + ".mp3"));
            player -> setVolume(80);
            player -> setPosition(0);
            player -> play();
        }

        ui->answerButton_1->setText(game.getAnswer(type, 1));
        ui->answerButton_2->setText(game.getAnswer(type, 2));
        ui->answerButton_3->setText(game.getAnswer(type, 3));
        ui->answerButton_4->setText(game.getAnswer(type, 4));
    }
}

void MainWindow::checkAnswer(QString type, int id)
{
    if(game.checkAnswerId(type, id-1)){
        updatePlayScreen(type);
    }
    else
    {
        player -> setVolume(30);
        on_statButton_clicked();
    }
}

void MainWindow::backgroundMusic()
{
    player -> setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath()+"/../../gui-1h2017-14/res/music/"+game.bckgMusic()+".mp3"));
    player -> setVolume(30);
    player -> play();
}

void MainWindow::setNameAndScore()
{
    ui->name->setText("<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:18pt; color:#6aaa49;\">" +
            game.getPlayer().getName() +
            "</span></p></body></html>");
    ui->name_2->setText("<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:18pt; color:#6aaa49;\">" +
            game.getPlayer().getName() +
            "</span></p></body></html>");

    ui->score->setText("<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:18pt; color:#ffffff;\">" +
            QString::number(game.getPlayer().getSumScore()) +
            "</span></p></body></html>");
    ui->score_2->setText("<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:18pt; color:#ffffff;\">" +
            QString::number(game.getPlayer().getSumScore()) +
            "</span></p></body></html>");
}

void MainWindow::on_signupButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageSignup);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}

void MainWindow::on_cancelButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMenuLogout);
}

void MainWindow::on_signupButton_clicked()
{
    if (ui->username_2->text() != "" && ui->password_2->text() != "")
    {
        if(game.signup(ui->username_2->text(), ui->password_2->text()))
        {
            setNameAndScore();

            ui->gameWidget->setCurrentWidget(ui->pageMain);
            ui->menuWidget->setCurrentWidget(ui->pageMenuLogin);
        }
        else
        {
            ui->label_6->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"
                                 "Игрок с таким логином</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"
                                 "уже зарегистрирован!</span></p></body></html>");

        }
    }
    else
    {
        ui->label_6->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"
                             "Все поля должны быть заполнены!</span></p></body></html>");
    }

}

void MainWindow::on_creatorsButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageCreators);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}

void MainWindow::on_creatorsButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageCreators);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}
