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
public:
    QuestCards();
    ~QuestCards();
    QString getContent(QString type);
    int getNum(int N);
};

#endif // QUESTCARDS_H
