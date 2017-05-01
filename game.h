#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "music.h"
#include <QString>
#include <QList>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QApplication"

class Game
{
private:
    Player player;
    QuestCards *questCards[2];
    QSqlDatabase db;

public:
    Game();
    ~Game();

    Player getPlayer() const;
    void setPlayer(const Player &value);

    bool login(QString name, QString pass);
    void logout();
    bool isLogin();
    bool signup(QString name, QString pass);
    QSqlQuery getUserFromDB(QString username);
    QSqlQuery getStats();

    void connectDB();

    bool playGame(QString type);

    QString getAnswer(QString type, int id);
    QString getRightAnswerId(QString type);
    QString getRightAnswerCount(QString type);
    bool checkAnswerId(QString type, int id);
    void eraseContent(QString type);

    QString playBkgdMusic();
};

#endif // GAME_H
