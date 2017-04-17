#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <QString>
#include <QList>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QApplication"

class Game
{
private:
    Player player;
    QSqlDatabase db;
public:
    Game();
    ~Game();

    Player getPlayer() const;
    void setPlayer(const Player &value);

    void login(QString name, int ms, int fs, QString t);
    QString logout();
    QString signin(QString name, QString pass);
    void connectDB();
    QSqlQuery getStats();
    QSqlQuery getUserFromDB(QString username);
};

#endif // GAME_H
