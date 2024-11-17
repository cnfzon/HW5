#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);

int main(void) {
    const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* face[13] = {
        "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King"
    };
    int deck[4][13] = { 0 }; // Initialize all positions to 0

    srand(time(0)); // Seed for random number generation

    shuffle(deck);  // Shuffle the deck
    deal(deck, face, suit);  // Deal the cards
    return 0;
}

// Function to shuffle the deck
void shuffle(int wDeck[][13]) {
    int row, column, card;
    for (card = 1; card <= 52; card++) {
        do {
            row = rand() % 4;       // Random row (suit)
            column = rand() % 13;   // Random column (face)
        } while (wDeck[row][column] != 0); // Repeat if position already filled

        wDeck[row][column] = card; // Assign card number to position
    }
}

// Function to deal the cards
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]) {
    int card, row, column;
    for (card = 1; card <= 52; card++) {
        for (row = 0; row < 4; row++) {
            for (column = 0; column < 13; column++) {
                if (wDeck[row][column] == card) {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
