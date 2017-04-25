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
    Music gameMusic;
    QSqlDatabase db;

public:
    Game();
    ~Game();

    Player getPlayer() const;
    void setPlayer(const Player &value);

    void login(QString name, int ms, int fs, QString t);
    QString logout();
    QString signin(QString name, QString pass);
    QSqlQuery getUserFromDB(QString username);
    QSqlQuery getStats();

    void connectDB();

    bool playGame(QString type);

    QString getAnswer(QString type, int id);
    QString getRightAnswerName(QString type);    
    bool checkAnswerId(QString type, int id);
    void eraseContent(QString type);

    QString bckgMusic();
};

#endif // GAME_H
