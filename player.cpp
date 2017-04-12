#include "player.h"

QString Player::getName() const
{
    return name;
}

void Player::setName(const QString &value)
{
    name = value;
}

QString Player::getType() const
{
    return type;
}

void Player::setType(const QString &value)
{
    type = value;
}

void Player::addScore(unsigned int value)
{
    score += value;
}

unsigned int Player::getScore() const
{
    return score;
}

void Player::setScore(unsigned int value)
{
    score = value;
}

Player::Player()
{

}

Player::Player(QString n, unsigned int s, QString t)
{
    name = n;
    score = s;
    type = t;
}
