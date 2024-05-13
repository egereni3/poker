#include "Player.h"

Player::Player(const QString& name) : m_name(name), m_score(0) {}

void Player::dealHand(Deck& deck)
{
    m_hand.dealHand(deck);
}

void Player::swapCards(const QVector<int>& cardIndices, Deck& deck)
{
    m_hand.swapCard(cardIndices, deck);
}


QString Player::getName() const
{
    return m_name;
}

int Player::getScore() const
{
    return m_score;
}

void Player::resetScore()
{
    m_score = 0;
}

void Player::incrementScore()
{
    m_score+=1;
}

Hand Player::getHand() const
{
    return m_hand;
}


Hand* Player::getHandP()
{
    return &m_hand;
}

