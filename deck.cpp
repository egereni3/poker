#include "Deck.h"

Deck::Deck() : m_currentCardIndex(0)
{
    createDeck();
    shuffle();
}

void Deck::createDeck()
{
    m_deck.clear();
    for (int suit = Card::Hearts; suit <= Card::Spades; ++suit)
    {
        for (int rank = Card::Two; rank <= Card::Ace; ++rank)
        {
            m_deck.push_back(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_deck.begin(), m_deck.end(), g);
    m_currentCardIndex = 0;
}

Card Deck::dealCard()
{
    if (m_currentCardIndex >= (int) m_deck.size())
    {
        shuffle();
    }
    return m_deck[m_currentCardIndex++];
}

int Deck::getIndex() const{
    return m_currentCardIndex;
}

void Deck::resetIndex(){
    m_currentCardIndex = 0;
}
