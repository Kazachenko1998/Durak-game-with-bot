#include "dealer.h"
#include <iostream>
#include "dealer.h"
#include <ctime>
#include <cstdlib>

using namespace std;


Card Dealer::deck[allCard];
int Dealer::currentCard;
bool Dealer::tableRanks[Dealer::maxRanks];   // ранги карт, присутствующих на столе
Card *Dealer::trump;
int Dealer::currentHeadTrik;                 //номер хода в кону
Card *Dealer::noCard, *Dealer::pasCard; // карта - признак "нет карт" и "пас"

bool Card::operator>(const Card &card) {
    return (suit < card.suit && rank < card.rank);
}

//~Dealer();

int random() {
    int min = 0;
    int max = 53;
    max++;
    return abs(rand() % (max - min)) + min;
}


void Dealer::ShuffleDec() {
    srand(static_cast<unsigned int>(time(nullptr)));
    GenerateDeck();
    ClearTable();
    currentCard = 0;
    Dealer::trump = &Dealer::deck[allCard - 1];
    cout << trump->toString() << "--trump\n";
}

void Dealer::GenerateDeck() {
    int coutSucess = 0;
    for (auto &i : Dealer::deck) {
        i = Card();
    }
    for (int i = 0; i < allCard; ++i) {
        int j = random();
        while (Dealer::deck[j].suit != -1) {
            j = random();
        }
        Card newCard = Card((coutSucess % maxRanks), (coutSucess / maxRanks));
        Dealer::deck[j] = newCard;
        coutSucess++;
    }
}


bool Dealer::GetCard(Card *&outCard) {

    if (currentCard >= allCard) {
        outCard->rank = PAS;
        return false;
    } else {
        int i = currentCard;
        outCard = &deck[i];
        currentCard++;
        return true;
    }
}

bool Dealer::GetCard() {

    return (currentCard < allCard);
}

Card *Dealer::GetTrump() {
    return Dealer::trump;
}

int Dealer::getCurrentCard() {
    return currentCard;
}

const char *Dealer::SuitName(const Card *card) {
    return suits[card->suit];
}

const char *Dealer::RankName(const Card *card) {
    return ranks[card->rank];
}

int Dealer::SuitIndex(const Card *card) {
    return card->suit;
}

int Dealer::RankIndex(const Card *card) {
    return card->rank;
}

int Dealer::GetCurrentHeadTrik() {
    return *&currentHeadTrik;
}

void Dealer::addCurrentHeadTrik() {
    currentHeadTrik++;
}


bool Dealer::NextTrikEnable() {
    if (currentHeadTrik > 5)return false;
    for (auto &j : Dealer::headTrick) {
        for (auto &i : j) {
            if (i != nullptr && (i->rank == NOCARD || i->rank == PAS))
                return false;
        }
    }
    return true;
}

void Dealer::ShowCard(Card *card) {
    cout << card->toString();
}

void Dealer::ShowTable() {
    cout << "\n" << "------------------------------------------------------------------------------------------"
         << "\n|";
    for (int i = 0; i < Dealer::maxTrick; i++) {
        if (Dealer::headTrick[0][i] != nullptr)
            ShowCard(Dealer::headTrick[0][i]);
        else cout << "               ";
    }

    cout << "|\n|";
    for (int i = 0; i < Dealer::maxTrick; i++) {
        if (Dealer::headTrick[1][i] != nullptr)
            ShowCard(Dealer::headTrick[1][i]);
        else cout << "               ";
    }
    cout << "|\n" << "------------------------------------------------------------------------------------------"
         << "\n";
}

Card *Dealer::GetPas() {
    return nullptr;
}

Card *Dealer::GetNocard() {
    return nullptr;
}

Card *Dealer::GetLastCard() {
    auto *currentCard = new Card(100, 100);
    for (int i = 0; i < maxTrick; i++) {
        if (Dealer::headTrick[0][i] != nullptr)
            currentCard = Dealer::headTrick[0][i];
    }
    return currentCard;
}

Card *Dealer::GetLastDefendCard() {
    auto *currentCard = new Card(100, 100);
    for (int i = 0; i < maxTrick; i++) {
        if (Dealer::headTrick[1][i] != nullptr)
            currentCard = Dealer::headTrick[1][i];
    }
    return currentCard;
}

void Dealer::ClearTable() {
    currentHeadTrik = 0;
    for (auto &i : headTrick) {
        for (auto &j : i) {
            j = nullptr;
        }
    }
}

bool Dealer::CheckHeadTrick() {
    return true;
}

void Dealer::Attack(Card *card) {

}

void Dealer::Defend(Card *card) {
}

Dealer::~Dealer() = default;

//Dealer::getHeadTrick() {
//
//}

Card *Dealer::headTrick[2][Dealer::maxTrick];        // стол [0] - ход игрока, [1] - отбой карты

//Dealer::getHeadTrick() {
//    return *Dealer::headTrick;
//}


//Dealer::GetheadTrick() {
//    return Dealer::headTrick;
//}

bool Card::operator==(const Card &rhs) const {
    return suit == rhs.suit &&
           rank == rhs.rank;
}

bool Card::operator!=(const Card &rhs) const {
    return !(rhs == *this);
}

string Card::toString() {
    if (this->rank > 99)
        return "      &&&&     ";
    string result;
    result = Dealer::SuitName(this);
    result += *"  ";
    result += Dealer::RankName(this);
    return result;
}






