#ifndef MUSIC_H
#define MUSIC_H

#include "questcards.h"

class Music : public QuestCards
{
private:
    const QString type = "music";
    bool answerCheck = true;
public:
    Music();
    QString play();
    bool getAnswerCheck();
};

#endif // MUSIC_H
