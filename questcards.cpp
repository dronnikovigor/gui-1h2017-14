#include "questcards.h"

QuestCards::QuestCards()
{
}

QuestCards::~QuestCards()
{

}

QString QuestCards::getContent(QString type)
{
    QSqlQuery query("SELECT id FROM " + type);
    query.last();
    int N = query.at() + 1;
    if (N == usedContent.size())
        return "Game over";
    int randomId = getNum(N);
    query.exec("SELECT id, name FROM " + type + " WHERE id IS \"" + QString::number(randomId) + "\"");
    usedContent.append(randomId);
    QString id;
    QString name;
    while (query.next())
        {
        id = query.value(0).toString();
        name = query.value(1).toString();
        }

    return name;
}

int QuestCards::getNum(int N)
{
    int randomId = qrand() % N +1;
    QListIterator <int> id(usedContent);
    while(id.hasNext()){
        if(randomId == id.next()){
            return randomId = getNum(N);
        }
    }
    return randomId;
}
