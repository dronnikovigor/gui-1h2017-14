#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <game.h>

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

    void on_exitButton_clicked();

    void on_mainpageButton_clicked();

private:
    Ui::MainWindow *ui;

    Game game;
};

#endif // MAINWINDOW_H
