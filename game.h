#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <QString>

class Game
{
public:
    Game(const QString& player1Name, const QString& player2Name, Deck m_deck);
    QString playRound();
    QString getGameState() const;
    void dealCards();
    Player getPlayer1();
    Player* getPlayer1P();
    Player getPlayer2();
    Player* getPlayer2P();
    Deck* getDeck();

private:
    Player m_player1;
    Player m_player2;
    Deck m_deck;
};

#endif // GAME_H
