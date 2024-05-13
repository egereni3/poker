#include "Card.h"

Card::Card() : m_suit(), m_rank() {}

Card::Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank)
{
    const char* suitStrings[] = {"hearts", "diamonds", "clubs", "spades"};
    const char* rankStrings[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace"};

    filename = QString(":/PNG-cards-1.3/%1_of_%2.png").arg(rankStrings[m_rank - 2], suitStrings[m_suit]);
}

QString Card::toString() const
{
    const char* suitStrings[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* rankStrings[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    return QString("%1 of %2").arg(rankStrings[m_rank - 2], suitStrings[m_suit]);
}

QString Card::getFileName() const
{
    return filename;
}

int Card::getValue() const
{
    return m_rank == Ace ? 14 : m_rank;
}

QString Card::getSuit() const
{
    const char* suitStrings[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    return QString(suitStrings[m_suit]);
}

QString Card::getName() const
{
    return toString();
}

int Card::getNumber() const
{
    return m_suit * 100 + m_rank;
}

Card::Suit Card::getSuitEnum() const
{
    return m_suit;
}

Card::Rank Card::getRankEnum() const
{
    return m_rank;
}
