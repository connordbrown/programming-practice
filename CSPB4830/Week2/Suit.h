#ifndef _SUIT_H_ // this is the header guard
#define _SUIT_H_

#include <string>
#include <vector>
// 1) Create an enum class, Suit to represent the suit in a deck of cards
enum class Suit {Clubs, Diamonds, Hearts, Spades}; // {0, 1, 2, 3}

// 2) Create a struct, Card, to represent a card in a deck of cards.  You must
// use your Suit enum.  You may use any other values that you choose.
struct Card
{
    std::string name;
    Suit suit;
    int value;
};
// 3) Design a class, Deck.  Write down the fields and methods that this class should have.
// Don’t implement them!
class Deck
{
    public:
        // constructor
        Deck();

        // getter and setter
        std::vector<Card> get_cards();
        void set_cards(std::vector<Card> card_list);

        // methods
        void Shuffle();
        Card Draw();
        int Card_count();

    private:
        std::vector<Card> cards; // cards in deck
};

#endif // _SUIT_H_
