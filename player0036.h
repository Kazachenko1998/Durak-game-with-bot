
#include "player.h"
#include <string>
#include <iostream>


#ifndef ALENA_PLAYER0036_H

using namespace std;

class Player0036 : public PlayerAbstract {
private:
    const char *namePlayer;

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

}

void Player0036::PutCard() {

}

void Player0036::TakeCards() {

}

void Player0036::GetHeadTrick() {

}

void Player0036::TakeOneCard(Card *&nc) {

}

void Player0036::ShowCards() {

}

bool Player0036::INeedCard() {
    return false;
}

int Player0036::GetCardNum() {
    return 0;
}


#define ALENA_PLAYER0036_H

#endif //ALENA_PLAYER0036_H
