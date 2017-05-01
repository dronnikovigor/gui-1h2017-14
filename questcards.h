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
    bool getContent(QString type);
    int getNum();
    QString getRightAnswerId();
    void getRandomAns();

    QString getRandomAnsName(QString type, int id);

    bool checkAnswer(int id);
    void erase();

    bool checkUsedSize(QString type);
    QString backgroundMusic();
};

#endif // QUESTCARDS_H
