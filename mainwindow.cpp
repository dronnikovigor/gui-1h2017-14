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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}

void MainWindow::on_playMusic_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageMusic);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
    tmr->start();

    game.eraseContent("music");

    updatePlayScreen("music");
}

void MainWindow::on_playFilm_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageFilm);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);
    tmr->start();

    game.eraseContent("films");

    updatePlayScreen("films");
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
    ui->statsLabel->setText("Статистика");
    mediaPlayer->setVolume(bkgdMusicValue);
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_2_clicked()
{
    ui->statsLabel->setText("Статистика");
    ui->gameWidget->setCurrentWidget(ui->pageStats);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    statsOut();
}

void MainWindow::on_statButton_3_clicked()
{
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

void MainWindow::on_answerButton_5_clicked()
{
    checkAnswer("films", 1);
}

void MainWindow::on_answerButton_6_clicked()
{
    checkAnswer("films", 2);
}

void MainWindow::on_answerButton_7_clicked()
{
    checkAnswer("films", 3);
}

void MainWindow::on_answerButton_8_clicked()
{
    checkAnswer("films", 4);
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
    ui->gameWidget->setCurrentWidget(ui->pageHelp);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    howtoOut();
}

void MainWindow::on_rulesButton_2_clicked()
{
    ui->gameWidget->setCurrentWidget(ui->pageHelp);
    ui->menuWidget->setCurrentWidget(ui->pageMenuGame);

    howtoOut();
}

void MainWindow::on_rulesButton_3_clicked()
{
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

void MainWindow::updatePlayScreen(QString type)
{
    if(!game.playGame(type)){
        on_statButton_clicked();
        playerWin(type);
    }
    else
    {
        if (type=="music"){
            mediaPlayer->setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath() +
                                                   "/../../gui-1h2017-14/res/music/" +
                                                   game.getRightAnswerId(type) + ".mp3"));
            mediaPlayer->setVolume(musicPlayerValue);
            mediaPlayer->setPosition(0);
            mediaPlayer->play();
            ui->countRightAnswers->setText(game.getRightAnswerCount("music"));
            ui->answerButton_1->setText(game.getAnswer(type, 1));
            ui->answerButton_2->setText(game.getAnswer(type, 2));
            ui->answerButton_3->setText(game.getAnswer(type, 3));
            ui->answerButton_4->setText(game.getAnswer(type, 4));
        }
        else
        {
            ui->filmLabel->setPixmap(QPixmap(QApplication::applicationDirPath() +
                                                                  "/../../gui-1h2017-14/res/films/" +
                                                                  game.getRightAnswerId(type) + ".jpg"));
            ui->filmLabel->setScaledContents(true);
            ui->filmLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            ui->countRightAnswers->setText(game.getRightAnswerCount("films"));
            ui->answerButton_5->setText(game.getAnswer(type, 1));
            ui->answerButton_6->setText(game.getAnswer(type, 2));
            ui->answerButton_7->setText(game.getAnswer(type, 3));
            ui->answerButton_8->setText(game.getAnswer(type, 4));
        }
        ui->timerLabel->setText(QString::number(seconds=0));
    }
}

void MainWindow::checkAnswer(QString type, int id)
{
    if(game.checkAnswerId(type, id-1)){
        updatePlayScreen(type);
    }
    else
    {
        playerLose("Неверный ответ!");
    }
}

void MainWindow::backgroundMusic()
{
    mediaPlaylist->clear();
    for (int i = 0; i <= 60; i++)
        mediaPlaylist->addMedia(QUrl::fromLocalFile(QApplication::applicationDirPath()+"/../../gui-1h2017-14/res/music/"+game.playBkgdMusic()+".mp3"));
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
        playerLose("Закончилось время!");
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
    ui->statsLabel->setText(message);
    tmr->stop();
}


void MainWindow::playerWin(QString type)
{
    backgroundMusic();
    on_statButton_clicked();
    ui->statsLabel->setText("Вы выиграли!");
    if (type == "music")
        ui->countRightAnswers->setText(QString::number((game.getRightAnswerCount("music")).toInt()+1));
    else

        ui->countRightAnswers->setText(QString::number((game.getRightAnswerCount("films")).toInt()+1));
    tmr->stop();
}
