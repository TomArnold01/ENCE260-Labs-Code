#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"

typedef enum {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
} Suit_t;

typedef enum {
    ACE=1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} Rank_t;

typedef struct {
    int32_t rank;
    int32_t suit;

} Card_t;

Card_t makeCard(Rank_t rank, Suit_t suit) 
{
    Card_t v;
    v.rank = rank;
    v.suit = suit;
    return v;
}

bool isSnap(Card_t card1, Card_t card2)
{
    if (card1.rank == card2.rank) {
        return true;
    } else {
        return false;
    }
}
bool isTrump(Card_t card, Suit_t trumpSuit) 
{
    if (card.suit == trumpSuit) {
        return true;
    } else {
        return false;
    }
}

int main(void) 
{
Card_t card1 = makeCard(THREE, CLUBS);
Card_t card2 = makeCard(SEVEN, DIAMONDS);
Card_t card3 = makeCard(THREE, HEARTS);
puts(isSnap(card1, card2) ? "Snap!" : "No snap");
puts(isSnap(card1, card3) ? "Snap!" : "No snap");
puts(isTrump(card3, HEARTS) ? "Trump!" : "No Trump");
}