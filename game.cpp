#include "game.h"
Player Game::getPlayer() const
{
    return player;
}

void Game::setPlayer(const Player &value)
{
    player = value;
}

void Game::login(QString name, int ms, int fs, QString t)
{

    Player p(name, ms, fs, t);
    player = p;
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
    QSqlQuery query("SELECT login, music_score, film_score, (music_score+film_score) as total "
                    "FROM players "
                    "ORDER BY total DESC");

    return query;
}

QSqlQuery Game::getUserFromDB(QString username)
{
    if (!db.isOpen())
        connectDB();
    QSqlQuery query("SELECT login, password, music_score, film_score, type "
                    "FROM players "
                    "WHERE login IS \"" + username + "\"");
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

QString Game::playGame(QString type)
{
    if (type == "music"){
        return gameMusic.play();
    }

}


Game::Game()
{
    if (!db.isOpen())
        connectDB();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

Game::~Game()
{
    if (db.isOpen())
        db.close();
}
