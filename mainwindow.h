#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <game.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/qmediaplayer.h>
#include <QMediaPlaylist>
#include <QFile>
#include <QTimer>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playMusic_clicked();
    void on_playFilm_clicked();
    void on_mainpageButton_clicked();
    void on_statButton_clicked();
    void on_loginButton_clicked();
    void on_loginButton_3_clicked();
    void on_signupButton_clicked();
    void on_signupButton_2_clicked();
    void on_cancelButton_clicked();
    void on_cancelButton_2_clicked();
    void on_creatorsButton_clicked();
    void on_settingsButton_clicked();
    void on_rulesButton_clicked();
    void on_exitButton_clicked();

    void on_answerButton_1_clicked();
    void on_answerButton_2_clicked();
    void on_answerButton_3_clicked();
    void on_answerButton_4_clicked();
    void on_answerButton_5_clicked();
    void on_answerButton_6_clicked();
    void on_answerButton_7_clicked();
    void on_answerButton_8_clicked();

    void on_bkgdMusicVolumeSlider_valueChanged(int value);
    void on_musicPlayerVolumeSlider_valueChanged(int value);

    void updateTimer();
    void updateButton();
    void gameEnd();

private:
    Ui::MainWindow *ui;

    Game game;
    QMediaPlayer * mediaPlayer;
    QMediaPlaylist * mediaPlaylist;
    QTimer *tmr;
    QTimer *tmr_btn;
    QTimer *tmr_end;
    int bkgdMusicValue = 20;
    int musicPlayerValue = 80;
    int seconds;
    QString actualGame;
    bool checkInGame = false;

    void hideUserInfo();
    void showUserInfo();
    void hideSpecialButtons();
    void showSpecialButtons();
    void hideLoginButtons();
    void showLoginButtons();

    void statsOut();
    void howtoOut();
    void updatePlayScreen();
    void checkAnswer(int id);
    void backgroundMusic();
    void setNameAndScore();
    void playerLose(QString message);
    void playerWin();
};

#endif // MAINWINDOW_H
