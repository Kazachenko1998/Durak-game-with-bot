#include <iostream>
#include "dealer.h"
#include <ctime>
#include <cstdlib>

using namespace std;

bool Card::operator>(const Card &card) {
    return (suit < card.suit && rank < card.rank);
}

//~Dealer();

int random() {
    int min = 0;
    int max = 54;
    max++;
    return abs(rand() % (max - min)) + min;
}

void Dealer::ShuffleDec() {
    for (int i = 0; i < 54; ++i) {
        int j;
        int coutSucess = 0;
        while (deck[j = random()].operator==(NULL) || coutSucess < Dealer::allCard);
        Dealer::deck[j] = *new Card((coutSucess % Dealer::maxRanks) + 1, (coutSucess / Dealer::maxRanks) + 1);
    }
}


bool Dealer::GetCard(Card *&outCard) {
//    if ()
    return false;
}

Card *Dealer::GetTrump() {
    return NULL;
}

int Dealer::getcurrentCard() {
    return 0;
}

const char *Dealer::SuitName(const Card *card) {
    string *s = new string(card->suit + "");
    auto *intStr = reinterpret_cast<char *>(s);
    return intStr;
}

const char *Dealer::RankName(const Card *card) {
    string *s = new string(card->rank + "");
    auto *intStr = reinterpret_cast<char *>(s);
    return intStr;
}

int Dealer::SuitIndex(const Card *card) {
    return card->suit;
}

int Dealer::RankIndex(const Card *card) {
    return card->rank;
}

int Dealer::GetCurrentHeadTrik() {
    return 0;
}

bool Dealer::NextTrikEnable() {
    return false;
}

void Dealer::ShowCard(const Card *card) {

}

void Dealer::ShowTable() {

}

Card *Dealer::GetPas() {
    return NULL;
}

Card *Dealer::GetNocard() {
    return NULL;
}

Card *Dealer::GetLastCard() {
    return NULL;
}

Card *Dealer::GetLastDefendCard() {
    return NULL;
}

void Dealer::ClearTable() {

}

bool Dealer::CheckHeadTrick() {
    return false;
}

void Dealer::Attack(Card *card) {

}

void Dealer::Defend(Card *card) {

}

Dealer::~Dealer() {

}

void Dealer::GenerateDeck() {

}

