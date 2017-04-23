#ifndef QUESTCARDS_H
#define QUESTCARDS_H

#include <QString>
#include <QSqlQuery>
#include "QTime"
#include <QList>

class QuestCards
{
private:
    QList <int> usedContent;
    int answerId;
    QList <int> randomId;
    int N;
public:
    QuestCards();
    ~QuestCards();
    void getContent(QString type);
    int getNum();
    QString getNameFrDB(QString type);
    void getRandomAns();

    QList<int> getRandomIdList();
    QString getRandomAnsName(QString type, int id);

    void erase();
};

#endif // QUESTCARDS_H
