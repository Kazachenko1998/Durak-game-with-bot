
#include "player.h"
#include <string>
#include <list>
#include <iostream>


#ifndef ALENA_PLAYER0036_H

using namespace std;

class Player0036 : public PlayerAbstract {
private:
    const char *namePlayer;
    bool turn;
    std::list<Card> listCard;
public:
    Player0036(const char *name) {
        namePlayer = name;
    }

    virtual void YouTurn(bool b);

    virtual void PutCard();

    virtual void TakeCards();

    virtual void GetHeadTrick();

    virtual void TakeOneCard(Card *&nc);

    virtual void ShowCards();

    virtual bool INeedCard();

    virtual int GetCardNum();
};
// Реализуйте интерфейсы абстрактного класса
// Доступные методы из класса Dealer можно увидеть в файле dealer.h

void Player0036::YouTurn(bool b) {
    turn = b;
}

void Player0036::PutCard() {
   int i = Dealer::GetCurrentHeadTrik();
    for (std::list<Card>::iterator it = this->listCard.begin(); it != this->listCard.end(); it++)
    {
        if ((*it).suit!=Dealer::GetTrump()->suit);{

        }
    }
    std::cout << '\n';
   Dealer::headTrick[0][i] = &Player0036::listCard.back();
}

void Player0036::TakeCards() {

}

void Player0036::GetHeadTrick() {
    int i = Dealer::GetCurrentHeadTrik();
    Dealer::headTrick[1][i] = &Player0036::listCard.back();
    Dealer::addCurrentHeadTrik();
}

void Player0036::ShowCards() {
    for (std::list<Card>::iterator it = this->listCard.begin(); it != this->listCard.end(); it++)
        cout << (*it).toString() << ' ';

    std::cout << '\n';


}

void Player0036::TakeOneCard(Card *&nc) {
    listCard.push_back(*nc);
}


bool Player0036::INeedCard() {
    return listCard.size() < 6;
}

int Player0036::GetCardNum() {
    return static_cast<int>(listCard.size());
}


#define ALENA_PLAYER0036_H

#endif //ALENA_PLAYER0036_H
