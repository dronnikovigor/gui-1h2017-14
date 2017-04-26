#include "questcards.h"

QuestCards::QuestCards()
{
}

QuestCards::~QuestCards()
{

}

QString QuestCards::getRightAnswerId()
{    
    usedContent.append(answerId);    
    return QString::number(answerId);
}

bool QuestCards::getContent(QString type)
{
    if (checkN(type)){
        answerId = getNum();
        getRandomAns();
        randomId.insert(qrand()%4, answerId);
        return true;
    }
    else
        return false;
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
    QSqlQuery query("SELECT id, name FROM " + type + " WHERE id IS \"" + QString::number(randomId.at(id)) + "\"");
    QString id_str;
    QString name_str;
    while (query.next())
        {
        id_str = query.value(0).toString();
        name_str = query.value(1).toString();
        }

    return name_str.left(30);
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

bool QuestCards::checkN(QString type)
{
    QSqlQuery query("SELECT id FROM " + type);
    query.last();
    N = query.at() + 1;
    if (N == usedContent.size())
        return false;
    return true;
}

QString QuestCards::backgroundMusic()
{
    QSqlQuery query("SELECT id FROM music");
    query.last();
    return QString::number((qrand() % (query.at()+1))+1);
}
