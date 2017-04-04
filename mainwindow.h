#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>

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

    void on_exitOnMain_triggered();

    void on_exitGame_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
