#include "Music.h"
Music::Music():QuestCards()
{

}

bool Music::play()
{
    return getContent(type);
}

