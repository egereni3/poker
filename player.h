#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "deck.h"
#include <QString>

class Player
{
public:
    Player(const QString& name);

    void dealHand(Deck& deck);
    void swapCards(const QVector<int>& cardIndices, Deck& deck);
    QString getName() const;
    int getScore() const;
    void incrementScore();
    Hand getHand() const;
    Hand* getHandP();
    void setName(QString name);
    void resetScore();

private:
    QString m_name;
    int m_score;
    Hand m_hand;
};

#endif // PLAYER_H
