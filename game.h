#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <QString>

class Game
{
private:
    Player player;

public:
    Game();
    ~Game();

    Player getPlayer() const;
    void setPlayer(const Player &value);

    QString login(QString name, QString pass);
    QString logout();
    QString signin(QString name, QString pass);
};

#endif // GAME_H