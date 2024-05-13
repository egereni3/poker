// Game.cpp
#include "Game.h"
#include "deck.h"
#include "qdebug.h"

Game::Game(const QString& player1Name, const QString& player2Name, Deck deck)
    : m_player1(player1Name), m_player2(player2Name), m_deck(deck) {}

QString Game::playRound(){
    // Sort by value
    m_player1.getHandP()->sortValue();
    m_player2.getHandP()->sortValue();

    QString player1Best = m_player1.getHandP()->getBest();
    QString player2Best = m_player2.getHandP()->getBest();
    QString output = "";

    if (player1Best > player2Best) {
        output = m_player1.getName() + " wins with " + player1Best;
        m_player1.incrementScore();
    } else if (player1Best < player2Best) {
        output = m_player2.getName() + " wins with " + player2Best;
        m_player2.incrementScore();
    } else {
        int player1Value = 0;
        int player2Value = 0;

        for (Card i : m_player1.getHand().getCards()){
            player1Value += i.getValue();
        }

        for (Card i : m_player2.getHand().getCards()){
            player1Value += i.getValue();
        }

        if (player1Value > player2Value) {
            output = m_player1.getName() + " wins with higher value cards";
            m_player1.incrementScore();
        } else if (player1Value < player2Value) {
            output = m_player2.getName() + " wins with higher value cards";
            m_player2.incrementScore();
        } else {
            output = "It's a tie!";
            m_player1.incrementScore();
            m_player2.incrementScore();
        }
    }
    return output;
}

void Game::dealCards()
{
    // Deal hands
    m_player1.dealHand(m_deck);
    m_player2.dealHand(m_deck);
}

QString Game::getGameState() const
{

}

Player Game::getPlayer1()
{
    return m_player1;
}

Player* Game::getPlayer1P()
{
    return &m_player1;
}

Player Game::getPlayer2()
{
    return m_player2;
}

Player* Game::getPlayer2P()
{
    return &m_player2;
}

Deck* Game::getDeck()
{
    return &m_deck;
}

