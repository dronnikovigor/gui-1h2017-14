#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
private:
    QString name;
    unsigned int score;
    QString type;

public:
    Player();
    Player(QString n, unsigned int s);
    ~Player();

    QString getName() const;
    void setName(const QString &value);

    unsigned int getScore() const;
    void setScore(unsigned int value);

    QString getType() const;
    void setType(const QString &value);

};

#endif // PLAYER_H
