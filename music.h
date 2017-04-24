#ifndef MUSIC_H
#define MUSIC_H

#include "questcards.h"

class Music : public QuestCards
{
private:
    const QString type = "music";
public:
    Music();
    void play();
};

#endif // MUSIC_H
