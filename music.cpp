#include "Music.h"
Music::Music():QuestCards()
{

}

QString Music::play()
{
    return getContent(type);
}

bool Music::getAnswerCheck()
{
    return answerCheck;
}
