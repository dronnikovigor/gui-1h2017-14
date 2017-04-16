#include "player.h"

Player::Player()
{
    name = "None";
    musicScore = 0;
    filmScore = 0;
    type = "User";
}

Player::Player(QString n, int ms, int fs, QString t)
{
    name = n;
    musicScore = ms;
    filmScore = fs;
    type = t;
}
Player::~Player()
{

}

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

int Player::getMusicScore() const
{
    return musicScore;
}

void Player::setMusicScore(int value)
{
    musicScore = value;
}
int Player::getFilmScore() const
{
    return filmScore;
}

void Player::setFilmScore(int value)
{
    filmScore = value;
}

int Player::getSumScore() const
{
    return sumScore;
}

void Player::setSumScore(int value)
{
    sumScore = value;
}

void Player::addMusicScore(int value)
{
    musicScore += value;
    sumScore = musicScore + filmScore;
}

void Player::addFilmScore(int value)
{
    filmScore += value;
    sumScore = musicScore + filmScore;
}
