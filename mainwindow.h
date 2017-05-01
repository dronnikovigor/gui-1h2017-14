#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <game.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/qmediaplayer.h>
#include <QFile>

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

    void on_exitButton_2_clicked();

    void on_exitButton_3_clicked();

    void on_mainpageButton_clicked();

    void on_statButton_clicked();

    void on_statButton_2_clicked();

    void on_statButton_3_clicked();

    void on_loginButton_clicked();

    void on_cancelButton_clicked();

    void on_loginButton_3_clicked();

    void on_answerButton_1_clicked();

    void on_answerButton_2_clicked();

    void on_answerButton_3_clicked();

    void on_answerButton_4_clicked();

    void on_signupButton_2_clicked();

    void on_cancelButton_2_clicked();

    void on_signupButton_clicked();

    void on_creatorsButton_clicked();

    void on_creatorsButton_2_clicked();

    void on_settingsButton_clicked();

    void on_bkgdMusicVolumeSlider_valueChanged(int value);

    void on_musicPlayerVolumeSlider_valueChanged(int value);

    void on_rulesButton_clicked();

    void on_rulesButton_2_clicked();

    void on_rulesButton_3_clicked();

    void on_settingsButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Game game;
    QMediaPlayer * mediaPlayer;
    int bkgdMusicValue = 20;
    int musicPlayerValue = 80;

    void statsOut();
    void howtoOut();
    void updatePlayScreen(QString type);
    void checkAnswer(QString type, int id);
    void backgroundMusic();
    void setNameAndScore();
};

#endif // MAINWINDOW_H
