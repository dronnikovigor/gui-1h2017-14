#include "game.h"

Player Game::getPlayer() const
{
    return player;
}

void Game::setPlayer(const Player &value)
{
    player = value;
}

QString Game::login(QString name, QString pass)
{
    QString str;
    return str;
}

QString Game::logout()
{
    QString str;
    return str;
}

QString Game::signin(QString name, QString pass)
{
    QString str;
    return str;
}

QSqlQuery Game::getStats()
{
    if (!db.isOpen())
        connectDB();
    QSqlQuery query("SELECT login, music_score, film_score, (music_score+film_score) as total FROM players ORDER BY total DESC");

    return query;
}

void Game::connectDB()
{
    if (!db.isOpen())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QApplication::applicationDirPath()+"/../../gui-1h2017-14/db/database.db");
        db.open();
    }
}

Game::Game()
{
    if (!db.isOpen())
        connectDB();
}

Game::~Game()
{
    if (db.isOpen())
        db.close();
}
