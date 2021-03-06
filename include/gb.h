#ifndef GB_H
#define GB_H

#include <ctime>
#include <vector>
#include "piles.h"
#include "card.h"
#include "color.h"
#include "cursor.h"

class GameBoard
{
public:
    GameBoard(void);
    ~GameBoard(void);

private:
    enum class select
    {
        card, // If selecting card/pile of cards
        dest  // If selecting destination for card/pile of cards
    };
    bool gamedone;
    bool gamestart;
    bool gamewin;
    card ** deck;
    card * hiddencard;
    DynamicCursor * c;
    int score, srcind, destind;
    pile src, dest;
    time_t starttime;
    select state;
    std::vector<card *> * gb;

public:
    bool getDone();
    bool getWon();
    int getScore(void);
    time_t getElapsed(void);
    void input(int inp);

private:
    int amountRevealed(pile p);
    bool canmove(pile src, pile dest, int srcind, int destind);
    card * lastRevealed(pile p);
    void print(void);
    void printBackground(void);
    void printCard(int y, int x, card * c);
    void printCursor(void);
    void printDeck(int y, int x);
    void printEmptyCard(int y, int x);
    void printHiddenCard(int y, int x);
    void refresh(void);
};

#endif
