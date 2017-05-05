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
    ui->widgetSettings->setAutoFillBackground(true);
    ui->widgetSettings->setPalette(palette);

    setNameAndScore();

    ui->gameWidget->setCurrentWidget(ui->pageMain);
    ui->menuWidget->setCurrentWidget(ui->pageMenuLogout);

    mediaPlayer = new QMediaPlayer;
    mediaPlaylist = new QMediaPlaylist(mediaPlayer);
    backgroundMusic();

    seconds = 0;
    tmr = new QTimer(this);
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTimer()));

    tmr_btn = new QTimer(this);
    tmr_btn->setInterval(5000);
    connect(tmr_btn, SIGNAL(timeout()), this, SLOT(updateButton()));

    tmr_end = new QTimer(this);
    tmr_end->setInterval(5000);
    connect(tmr_end, SIGNAL(timeout()), this, SLOT(gameEnd()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}

void MainWindow::on_playMusic_clicked()
{
    actualGame = "music";
    ui->gameWidget->setCurrentWidget(ui->pageMusic);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
    tmr->start();
    tmr_btn->start();

    game.eraseContent(actualGame);

    updatePlayScreen();
}

void MainWindow::on_playFilm_clicked()
{
    actualGame = "films";
    ui->gameWidget->setCurrentWidget(ui->pageFilm);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
    tmr->start();
    tmr_btn->start();

    game.eraseContent(actualGame);

    updatePlayScreen();
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
    tmr_end->stop();
    mediaPlayer->setVolume(bkgdMusicValue);
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
    tmr_end->stop();
    ui->statsLabel->setText("Статистика");
    mediaPlayer->setVolume(bkgdMusicValue);
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_2_clicked()
{
    tmr_end->stop();
    ui->statsLabel->setText("Статистика");
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_3_clicked()
{
    tmr_end->stop();
    ui->statsLabel->setText("Статистика");
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
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

void MainWindow::on_answerButton_1_clicked()
{
    checkAnswer(1);
}

void MainWindow::on_answerButton_2_clicked()
{
    checkAnswer(2);
}

void MainWindow::on_answerButton_3_clicked()
{
    checkAnswer(3);
}

void MainWindow::on_answerButton_4_clicked()
{
    checkAnswer(4);
}

void MainWindow::on_answerButton_5_clicked()
{
    checkAnswer(1);
}

void MainWindow::on_answerButton_6_clicked()
{
    checkAnswer(2);
}

void MainWindow::on_answerButton_7_clicked()
{
    checkAnswer(3);
}

void MainWindow::on_answerButton_8_clicked()
{
    checkAnswer(4);
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

void MainWindow::on_settingsButton_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageSettings);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}


void MainWindow::on_settingsButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageSettings);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
}

void MainWindow::on_bkgdMusicVolumeSlider_valueChanged(int value)
{
    bkgdMusicValue = value;
    mediaPlayer->setVolume(bkgdMusicValue);
}

void MainWindow::on_musicPlayerVolumeSlider_valueChanged(int value)
{
    musicPlayerValue = value;
}

void MainWindow::on_rulesButton_clicked()
{
    tmr_end->stop();
    ui->gameWidget->setCurrentWidget(ui->pageHelp);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    howtoOut();
}

void MainWindow::on_rulesButton_2_clicked()
{
    tmr_end->stop();
    ui->gameWidget->setCurrentWidget(ui->pageHelp);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    howtoOut();
}

void MainWindow::on_rulesButton_3_clicked()
{    
    tmr_end->stop();
    ui->gameWidget->setCurrentWidget(ui->pageHelp);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    howtoOut();
}

void MainWindow::statsOut()
{
    ui->statBrowser->clear();
    QSqlQuery query = game.getStats();

    QString html;
    html = "<table width=\"490\"><tr><td style=\"padding: 10px 0px 0px 10px\"><b>Имя игрока</b></td><td style=\"padding: 10px 0px 0px 5px\"><b>Музыка</b></td>"
           "<td style=\"padding: 10px 0px 0px 5px\"><b>Фильмы</b></td><td style=\"padding: 10px 0px 0px 5px\"><b>Всего</b></td></tr>";

    while (query.next())
        {
        QString login = query.value(0).toString();
        QString music_score = query.value(1).toString();
        QString film_score = query.value(2).toString();
        int total = music_score.toInt() + film_score.toInt();
        html += "<tr><td style=\"padding: 5px 0px 0px 10px\">" + login + "</td><td style=\"padding: 5px 0px 0px 5px\">" +
                music_score + "</td><td style=\"padding: 5px 0px 0px 5px\">" +
                film_score + "</td><td style=\"padding: 5px 0px 0px 5px\">" + QString::number(total) + "</td></tr>";
        }
    html += "</table>";
    ui->statBrowser->insertHtml(html);
}

void MainWindow::updatePlayScreen()
{
    if(!game.playGame(actualGame)){
        on_statButton_clicked();
        playerWin();
    }
    else
    {
        tmr_btn->setInterval(5000);
        if (actualGame=="music"){
            mediaPlayer->setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath() +
                                                   "/../../gui-1h2017-14/res/music/" +
                                                   game.getRightAnswerId(actualGame) + ".mp3"));
            mediaPlayer->setVolume(musicPlayerValue);
            mediaPlayer->setPosition(0);
            mediaPlayer->play();
            ui->countRightAnswers->setText(game.getRightAnswerCount(actualGame));
            ui->answerButton_1->setText(game.getAnswer(actualGame, 1));
            ui->answerButton_2->setText(game.getAnswer(actualGame, 2));
            ui->answerButton_3->setText(game.getAnswer(actualGame, 3));
            ui->answerButton_4->setText(game.getAnswer(actualGame, 4));
        }
        else
        {
            ui->filmLabel->setPixmap(QPixmap(QApplication::applicationDirPath() +
                                                                  "/../../gui-1h2017-14/res/films/" +
                                                                  game.getRightAnswerId(actualGame) + ".jpg"));
            ui->filmLabel->setScaledContents(true);
            ui->filmLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            ui->countRightAnswers->setText(game.getRightAnswerCount(actualGame));
            ui->answerButton_5->setText(game.getAnswer(actualGame, 1));
            ui->answerButton_6->setText(game.getAnswer(actualGame, 2));
            ui->answerButton_7->setText(game.getAnswer(actualGame, 3));
            ui->answerButton_8->setText(game.getAnswer(actualGame, 4));
        }
        ui->timerLabel->setText(QString::number(seconds=0));
    }
}

void MainWindow::checkAnswer(int id)
{
    if(game.checkAnswerId(actualGame, id-1)){
        updatePlayScreen();
    }
    else
    {
        if (actualGame == "music")
            playerLose("<table width=\"490\"><tr><td style=\"padding: 150px 10px 10px 10px;\"><center>Неверный ответ!<br>Это был трек "
                       + game.getRightAnswerNameStr(actualGame) + ".</center></td></tr></table>");
        else
            playerLose("<table width=\"490\"><tr><td style=\"padding: 150px 10px 10px 10px;\"><center>Неверный ответ!<br>Это был фильм "
                       + game.getRightAnswerNameStr(actualGame) + ".</center></td></tr></table>");
    }
}

void MainWindow::backgroundMusic()
{
    mediaPlaylist->clear();
    QDir dir(QApplication::applicationDirPath()+"/../../gui-1h2017-14/res/background_music/");
    if (dir.exists())
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            mediaPlaylist->addMedia(QUrl::fromLocalFile(QApplication::applicationDirPath()+
                                                        "/../../gui-1h2017-14/res/background_music/"+
                                                        fileInfo.fileName()));
        }
    }
    mediaPlayer->setPlaylist(mediaPlaylist);
    mediaPlayer->setVolume(bkgdMusicValue);
    mediaPlayer->play();
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

void MainWindow::updateTimer()
{
    ui->timerLabel->setText(QString::number(++seconds));
    if (seconds == 60)
        playerLose("<table width=\"490\"><tr><td style=\"padding: 170px 10px 10px 10px;\"><center>Закончилось время!</center></td></tr></table>");
}

void MainWindow::updateButton()
{
    tmr_btn->setInterval(100);
    if (actualGame == "music")
    {
        if (ui->answerButton_1->text().size() == 0 ||
                ui->answerButton_2->text().size() == 0 ||
                ui->answerButton_3->text().size() == 0 ||
                ui->answerButton_4->text().size() == 0)
        {
            ui->answerButton_1->setText(game.getAnswer(actualGame, 1));
            ui->answerButton_2->setText(game.getAnswer(actualGame, 2));
            ui->answerButton_3->setText(game.getAnswer(actualGame, 3));
            ui->answerButton_4->setText(game.getAnswer(actualGame, 4));
            tmr_btn->setInterval(3000);
        }
        else
        {
            ui->answerButton_1->setText(ui->answerButton_1->text().remove(0,1));
            ui->answerButton_2->setText(ui->answerButton_2->text().remove(0,1));
            ui->answerButton_3->setText(ui->answerButton_3->text().remove(0,1));
            ui->answerButton_4->setText(ui->answerButton_4->text().remove(0,1));
        }
    }
    else
    {
        if (ui->answerButton_5->text().size() == 0 ||
                ui->answerButton_6->text().size() == 0 ||
                ui->answerButton_7->text().size() == 0 ||
                ui->answerButton_8->text().size() == 0)
        {
            ui->answerButton_5->setText(game.getAnswer(actualGame, 1));
            ui->answerButton_6->setText(game.getAnswer(actualGame, 2));
            ui->answerButton_7->setText(game.getAnswer(actualGame, 3));
            ui->answerButton_8->setText(game.getAnswer(actualGame, 4));
            tmr_btn->setInterval(3000);
        }
        else
        {
            ui->answerButton_5->setText(ui->answerButton_5->text().remove(0,1));
            ui->answerButton_6->setText(ui->answerButton_6->text().remove(0,1));
            ui->answerButton_7->setText(ui->answerButton_7->text().remove(0,1));
            ui->answerButton_8->setText(ui->answerButton_8->text().remove(0,1));
        }
    }
}

void MainWindow::howtoOut()
{
    ui->howtoBrowser->clear();
    QFile file(":/text/res/how_to_play.txt");
    if (!file.open(QIODevice::ReadOnly))
        return;
    else
    {
         QString html;
         html = "<p style=\"margin: 30px 20px 20px 20px;\">"+ QString::fromUtf8(file.readAll())+"</p>";
         ui->howtoBrowser->insertHtml(html);
    }
}

void MainWindow::playerLose(QString message)
{
    backgroundMusic();
    on_statButton_clicked();
    ui->statsLabel->setText("");
    ui->statBrowser->clear();
    ui->statBrowser->insertHtml(message);
    tmr_end->start();
    tmr->stop();
}

void MainWindow::playerWin()
{
    backgroundMusic();
    on_statButton_clicked();
    ui->statsLabel->setText("");
    ui->statBrowser->clear();
    ui->statsLabel->setText("<table width=\"490\"><tr><td style=\"padding: 170px 10px 10px 10px;\"><center>Вы выиграли!</center></td></tr></table>");
    if (actualGame == "music")
        ui->countRightAnswers->setText(QString::number((game.getRightAnswerCount(actualGame)).toInt()+1));
    else

        ui->countRightAnswers->setText(QString::number((game.getRightAnswerCount(actualGame)).toInt()+1));
    tmr->stop();
    tmr_end->start();
}

void MainWindow::gameEnd()
{
    on_statButton_clicked();
}
