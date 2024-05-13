#include "Hand.h"
#include "qdebug.h"

Hand::Hand() : m_hand(5) {}

void Hand::dealHand(Deck& deck)
{
    for (int i = 0; i < 5; ++i)
    {
        m_hand[i] = deck.dealCard();
    }
}

void Hand::sortValue()
{
    auto cardValueComparator = [](const Card& card) {
        // Consider Ace as 14 when not part of a straight
        if (card.getRankEnum() == Card::Rank::Ace)
            return 14;
        return static_cast<int>(card.getRankEnum());
    };

    // Bubble sort algorithm
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < m_hand.size() - 1; ++i) {
            if (cardValueComparator(m_hand[i]) > cardValueComparator(m_hand[i + 1])) {
                std::swap(m_hand[i], m_hand[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void Hand::sortGroup()
{
    sortValue();

    // Sort by frequency
    std::stable_sort(m_hand.begin(), m_hand.end(), [this](const Card& a, const Card& b) {
        // Count the occurrences of cards
        int countA = std::count_if(m_hand.begin(), m_hand.end(), [&](const Card& card) {
            return card.getRankEnum() == a.getRankEnum();
        });
        int countB = std::count_if(m_hand.begin(), m_hand.end(), [&](const Card& card) {
            return card.getRankEnum() == b.getRankEnum();
        });

        // If frequencies are equal, sort by card value
        if (countA == countB) {
            return cardValue(a) < cardValue(b);
        }
        // Otherwise sort by frequency
        return countA > countB;
    });
}


QString Hand::getBest()
{
    sortValue();

    QMap<Card::Rank, int> rankCounts;
    for (const Card& card : m_hand) {
        ++rankCounts[card.getRankEnum()];
    }

    // Check for straight flush
    if (isStraight(m_hand) && isFlush(m_hand)) {
        return "stfl";
    }

    // Check for four of a kind, full house, three of a kind, two pair, and one pair
    int fourOfAKindCount = 0;
    int threeOfAKindCount = 0;
    int pairCount = 0;
    for (int count : rankCounts) {
        if (count == 4) {
            ++fourOfAKindCount;
        } else if (count == 3) {
            ++threeOfAKindCount;
        } else if (count == 2) {
            ++pairCount;
        }
    }

    if (fourOfAKindCount > 0) {
        return "four of a kind";
    } else if (threeOfAKindCount > 0 && pairCount > 0) {
        return "full house";
    } else if (isFlush(m_hand)) {
        return "flush";
    } else if (isStraight(m_hand)) {
        return "straight";
    } else if (threeOfAKindCount > 0) {
        return "trio";
    } else if (pairCount == 2) {
        return "two pair";
    } else if (pairCount == 1) {
        return "one pair";
    }

    return "high";
}

void Hand::setHand(const QVector<int>& cardValues)
{
    for (int i = 0; i < 5; ++i)
    {
        int suit = cardValues[i] / 100;
        int rank = cardValues[i] % 100;
        m_hand[i] = Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
    }
}

void Hand::setHand(const QVector<Card>& sortedHand)
{
    m_hand = sortedHand;
    /*int count = 0;
    for (Card index : sortedHand)
    {
        m_hand.replace(count,index);
        count++;
    }*/

}

QVector<Card> Hand::swapCard(const QVector<int>& cardIndices, Deck& deck)
{

    QVector<Card> test = m_hand;
    int count = 0;
    for (int index : cardIndices)
    {
        if (count <= 2){
            test.replace(index,deck.dealCard());
        }
        else
        {
            break;
        }
        count++;
    }
    setHand(test);
    return test;

}

QString Hand::rankToString(Card::Rank rank) const
{
    switch (rank)
    {
    case Card::Two: return "2";
    case Card::Three: return "3";
    case Card::Four: return "4";
    case Card::Five: return "5";
    case Card::Six: return "6";
    case Card::Seven: return "7";
    case Card::Eight: return "8";
    case Card::Nine: return "9";
    case Card::Ten: return "10";
    case Card::Jack: return "Jack";
    case Card::Queen: return "Queen";
    case Card::King: return "King";
    case Card::Ace: return "Ace";
    }
    return "";
}

QString Hand::suitToString(Card::Suit suit) const
{
    switch (suit)
    {
    case Card::Hearts: return "Hearts";
    case Card::Diamonds: return "Diamonds";
    case Card::Clubs: return "Clubs";
    case Card::Spades: return "Spades";
    }
    return "";
}

int Hand::cardValue(const Card& card) const
{
    return card.getRankEnum() == Card::Ace ? 14 : card.getRankEnum();
}

QVector<Card> Hand::getCards() const
{
    return m_hand;
}

bool Hand::isStraight(const QVector<Card>& sortedHand) const
{
    for (int i = 0; i < sortedHand.size() - 1; ++i) {
        if (sortedHand[i + 1].getValue() - sortedHand[i].getValue() != 1) {
            if (!(sortedHand[i].getValue() == 14 && sortedHand[i + 1].getValue() == 2)) {
                return false;
            }
        }
    }
    return true;
}


bool Hand::isFlush(const QVector<Card>& sortedHand) const
{
    Card::Suit suit = sortedHand[0].getSuitEnum();
    for (const Card& card : sortedHand) {
        if (card.getSuitEnum() != suit) {
            return false;
        }
    }
    return true;
}

