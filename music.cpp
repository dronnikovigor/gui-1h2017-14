#include "Music.h"
Music::Music():QuestCards()
{

}

void Music::play()
{
    getContent(type);
}

bool Music::getAnswerCheck()
{
    return answerCheck;
}
