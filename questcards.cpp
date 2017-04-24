#include "questcards.h"

QuestCards::QuestCards()
{
}

QuestCards::~QuestCards()
{

}

QString QuestCards::getNameFrDB(QString type)
{
    QSqlQuery query("SELECT id, name FROM " + type + " WHERE id IS \"" + QString::number(answerId) + "\"");
    usedContent.append(answerId);
    QString id_str;
    QString name_str;
    while (query.next())
        {
        id_str = query.value(0).toString();
        name_str = query.value(1).toString();
        }

    return name_str;
}

void QuestCards::getContent(QString type)
{
    QSqlQuery query("SELECT id FROM " + type);
    query.last();
    N = query.at() + 1;
    /*if (N == usedContent.size())
        return "Game over";*/
    answerId = getNum();
    getRandomAns();
    randomId.insert(qrand()%4, answerId);
}

int QuestCards::getNum()
{
    int randomId = qrand() % N +1;
    QListIterator <int> id(usedContent);
    while(id.hasNext()){
        if(randomId == id.next()){
            return randomId = getNum();
        }
    }
    return randomId;
}

void QuestCards::getRandomAns()
{
    if (N > 3){
        bool check = true;
        randomId.clear();
        for (int i = 0; i < 3; i++){
            int id = qrand() % N +1;
            QListIterator <int> id_iter(randomId);
            if (id == answerId){
                i--;
                continue;
            }
            else
                while(id_iter.hasNext()){
                    if(id == id_iter.next()){
                        i--;
                        check = false;
                        break;
                    }
                }
            if(check)
                randomId.append(id);
            else
                check = true;
        }
    }
}

QString QuestCards::getRandomAnsName(QString type, int id)
{
    QSqlQuery query("SELECT id, name FROM " + type + " WHERE id IS \"" + QString::number(randomId.at(id-1)) + "\"");
    QString id_str;
    QString name_str;
    while (query.next())
        {
        id_str = query.value(0).toString();
        name_str = query.value(1).toString();
        }

    return name_str;
}

QList<int> QuestCards::getRandomIdList()
{
    return randomId;
}

void QuestCards::erase()
{
    usedContent.clear();
    randomId.clear();
    answerId = 0;
    N = 0;
}


bool QuestCards::answerCheck(int id)
{
    if (randomId.at(id) == answerId)
        return true;
    else
        return false;
}
