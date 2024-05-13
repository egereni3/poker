#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>

class Card
{
public:
    enum Suit {Hearts, Diamonds, Clubs, Spades};
    enum Rank {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

    Card();
    Card(Suit suit, Rank rank);
    QString toString() const;
    QPixmap getPixmap() const;
    int getValue() const;
    QString getSuit() const;
    QString getName() const;
    int getNumber() const;
    Suit getSuitEnum() const;
    Rank getRankEnum() const;
    QString getFileName() const;

private:
    Suit m_suit;
    Rank m_rank;
    QString filename;
};

#endif
