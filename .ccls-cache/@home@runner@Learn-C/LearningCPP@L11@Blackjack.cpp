#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <vector>
#include <ctime>

enum Famille {
    coeur, carreau, pique, trefle, familles_MAX
};

enum Rang {
    r_2,
    r_3,
    r_4,
    r_5,
    r_6,
    r_7,
    r_8,
    r_9,
    r_10,
    r_Valet,
    r_Dame,
    r_Roi,
    r_Ace,
    r_rang_MAX,
};

struct Card {
    Famille famille{};
    Rang rang{};
};

constexpr int g_playerMaxScore = 21;
constexpr int g_dealerMinScore = 17;
constexpr int g_deckSize = 52;

using Deck = std::array<Card, g_deckSize>;

void PrintCard(const Card &card) {

    std::string cardCode{};

    switch (card.famille) {
        case coeur:
            cardCode += "H";
            break;
        case carreau:
            cardCode += "D";
            break;
        case pique:
            cardCode += "S";
            break;
        case trefle:
            cardCode += "C";
            break;
        default:
            cardCode += "?";
            break;
    }

    switch (card.rang) {
        case r_2:
            cardCode += "2";
            break;
        case r_3:
            cardCode += "3";
            break;
        case r_4:
            cardCode += "4";
            break;
        case r_5:
            cardCode += "5";
            break;
        case r_6:
            cardCode += "6";
            break;
        case r_7:
            cardCode += "7";
            break;
        case r_8:
            cardCode += "8";
            break;
        case r_9:
            cardCode += "9";
            break;
        case r_10:
            cardCode += "10";
            break;
        case r_Valet:
            cardCode += "V";
            break;
        case r_Dame:
            cardCode += "D";
            break;
        case r_Roi:
            cardCode += "R";
            break;
        case r_Ace:
            cardCode += "A";
            break;
        default:
            cardCode += "?";
            break;
    }

    std::cout << cardCode << " ";
}

Deck CreateDeck() {

    Deck deck{};

    int index{0};

    for (int i{0}; i < Famille::familles_MAX; ++i) {
        for (int j{0}; j < Rang::r_rang_MAX; ++j) {
            deck[index] = Card{static_cast<Famille>(i), static_cast<Rang>(j)};
            ++index;
        }
    }

    return deck;
}

void PrintDeck(const Deck &deck) {
    std::cout << "Printing deck : \n";
    for (const auto &card: deck) {
        PrintCard(card);
    }
}

void PrintHand(const std::vector<Card> &hand) {
    for (const auto &card: hand) {
        PrintCard(card);
    }
    std::cout << "\n\n";
}

void DeckShuffle(Deck &deck) {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}

int GetCardValue(const Card &card) {
    switch (card.rang) {
        case Rang::r_2 :
            return 2;
        case Rang::r_3 :
            return 3;
        case Rang::r_4:
            return 4;
        case Rang::r_5 :
            return 5;
        case Rang::r_6 :
            return 6;
        case Rang::r_7 :
            return 7;
        case Rang::r_8 :
            return 8;
        case Rang::r_9 :
            return 9;
        case Rang::r_10 :
        case Rang::r_Valet :
        case Rang::r_Dame :
        case Rang::r_Roi :
            return 10;
        case Rang::r_Ace :
            return 11;
        default:
            return 0;
    }
}

struct Player {
    int score{0};
    std::string name{};
    std::vector<Card> hand;
};

void DealNetNextCard(const Deck &deck, int &currentCardIndex, Player &player) {
    Card card = deck[++currentCardIndex];
    player.hand.push_back(card);
    player.score += GetCardValue(card);
};

void PrintCurrentHandAndScores(const Player &player) {
    std::cout << "hand of " << player.name << "\n";
    std::cout << "score : " << player.score << "\n";
    std::cout << "hand : ";
    PrintHand(player.hand);
}

bool KeepPlaying() {
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

bool PlayBlackjack(const Deck &deck) {

    std::cout << "\n\n begin blackjack ! \n\n";

    int currentCardIndex{0};

    Player j1;
    j1.name = "jason";
    Player dealer;
    dealer.name = "dealer";

    DealNetNextCard(deck, currentCardIndex, dealer);
    DealNetNextCard(deck, currentCardIndex, j1);
    DealNetNextCard(deck, currentCardIndex, j1);

    PrintCurrentHandAndScores(dealer);
    PrintCurrentHandAndScores(j1);

    while (KeepPlaying()) {
        DealNetNextCard(deck, currentCardIndex, j1);

        PrintCurrentHandAndScores(dealer);
        PrintCurrentHandAndScores(j1);

        if (j1.score > g_playerMaxScore) {
            std::cout << "you lost your score is " << j1.score;
            return false;
        }
    }

    while (dealer.score < g_dealerMinScore) {
        DealNetNextCard(deck, currentCardIndex, dealer);
        PrintCurrentHandAndScores(dealer);
    }

    if (dealer.score > g_playerMaxScore) {
        std::cout << "dealer lost with score " << dealer.score << "you win !";
        return true;
    }

    if(j1.score > dealer.score){
        std::cout<<"you beat the dealer, you win !";
        return true;
    }else{
        std::cout<<"you lost";
        return false;
    }

}

int main() {


    PrintCard({coeur, r_2});

    Deck deck{CreateDeck()};

    PrintDeck(deck);

    DeckShuffle(deck);

    PrintDeck(deck);

    std::cout << GetCardValue(deck[0]);

    PlayBlackjack(deck);

    return 0;
}