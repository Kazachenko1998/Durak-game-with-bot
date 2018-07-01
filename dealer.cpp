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
static Card *Dealer::headTrick[2][Dealer::maxTrick];        // стол [0] - ход игрока, [1] - отбой карты

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
    srand(time(NULL));
    GenerateDeck();
    Dealer::trump = new Card(Dealer::deck[allCard-1].rank,Dealer::deck[allCard-1].suit);
    cout<<trump->toString()<<"-11111111111111111\n";

}

void Dealer::GenerateDeck(){
    int coutSucess = 0;
    for (int i = 0; i < allCard; ++i) {
        int j = random();
        while (Dealer::deck[j].suit != -1) {
            j = random();
        }
        Card newCard = Card((coutSucess % maxRanks), (coutSucess / maxRanks));
        Dealer::deck[j] = newCard;
        coutSucess++;
    }
};



bool Dealer::GetCard(Card *&outCard) {
//    if ()
    return false;
}

Card *Dealer::GetTrump() {
    return Dealer::trump;
}

int Dealer::getCurrentCard() {
    return 0;
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
    return 0;
}

bool Dealer::NextTrikEnable() {
    return false;
}

void Dealer::ShowCard(const Card *card) {
    Card resultCard(card->rank, card->suit);
    cout<<resultCard.toString();
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



string Card::toString() {

    string result;
    result = Dealer::SuitName(this);
    result += *"  ";
    result += Dealer::RankName(this);
    return result;
}





