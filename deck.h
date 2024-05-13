#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <random>

class Deck
{
public:
    Deck();
    void createDeck();
    void shuffle();
    Card dealCard();
    int getIndex() const;
    void resetIndex();

private:
    std::vector<Card> m_deck;
    int m_currentCardIndex;
};

#endif // DECK_H
