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

}

QString Game::logout()
{

}

QString Game::signin(QString name, QString pass)
{

}

QSqlQuery Game::getStats()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/../../gui-1h2017-14/db/database.db");
    db.open();

    QSqlQuery query("SELECT login, music_score, film_score FROM players");

    db.close();
    return query;
}


Game::Game()
{
}

Game::~Game()
{
}
