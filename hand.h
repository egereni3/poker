#ifndef HAND_H
#define HAND_H

#include "Deck.h"
#include <QVector>
#include <algorithm>


class Hand
{
public:
    Hand();
    void dealHand(Deck& deck);
    void sortValue();
    void sortGroup();
    QString getBest();
    void setHand(const QVector<int>& cardValues);
    void setHand(const QVector<Card>& sortedHand);
    QVector<Card> swapCard(const QVector<int>& cardIndices, Deck& deck);
    QVector<Card> getCards() const;
    QVector<Card> m_hand;
    bool isFlush(const QVector<Card>& sortedHand) const;
    bool isStraight(const QVector<Card>& sortedHand) const;
private:
    QString rankToString(Card::Rank rank) const;
    QString suitToString(Card::Suit suit) const;
    int cardValue(const Card& card) const;
};

#endif // HAND_H
