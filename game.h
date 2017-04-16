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

    QString login(QString name, QString pass);
    QString logout();
    QString signin(QString name, QString pass);
    void connectDB();
    QSqlQuery getStats();
};

#endif // GAME_H
