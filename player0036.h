
#include "dealer.h"
#include "player.h"
#include <string>
#include <list>
#include <iostream>


#ifndef ALENA_PLAYER0036_H

using namespace std;

class Player0036 : public PlayerAbstract {
private:
    const char *namePlayer;
    bool turn{};
    std::list<Card> listCard{};
public:
    explicit Player0036(const char *name) {
        namePlayer = name;
    }

    void YouTurn(bool b) override;

    void PutCard() override;

    void TakeCards() override;

    void GetHeadTrick() override;

    void TakeOneCard(Card *&nc) override;

    void ShowCards() override;

    bool INeedCard() override;

    int GetCardNum() override;
};
// Реализуйте интерфейсы абстрактного класса
// Доступные методы из класса Dealer можно увидеть в файле dealer.h

void Player0036::YouTurn(bool b) {
    turn = b;
}

bool checkCard(Card card) {
    for (int i = 0; i < Dealer::GetCurrentHeadTrik(); i++) {
        if (Dealer::headTrick[0][i]->rank == card.rank || Dealer::headTrick[1][i]->rank == card.rank) {
            return true;
        }
    }
    return false;
}

void Player0036::PutCard() {
    int i = Dealer::GetCurrentHeadTrik();
    Card currentCard = *new Card(100, 100);
    if (i == Dealer::maxTrick || listCard.empty()) {
        currentCard.rank = NOCARD;
        Dealer::headTrick[0][i] = new Card(currentCard.rank, currentCard.suit);
        delete(currentCard);
        return;
    }

    if (i == 0) {
        for (auto &it : this->listCard) {
            if (it.suit != Dealer::GetTrump()->suit && it.rank < currentCard.rank) {
                currentCard = it;
            }
        }
        if (currentCard.rank == 100) {
            for (auto &it : this->listCard) {
                if (it.rank < currentCard.rank) {
                    currentCard = it;
                }
            }
        }
    } else {
        for (auto &it : this->listCard) {
            if (it.suit != Dealer::GetTrump()->suit && it.rank < currentCard.rank && checkCard(it)) {
                currentCard = it;
            }
        }
    }
    if (currentCard.rank == 100) {
        currentCard.rank = PAS;
    }

    Dealer::headTrick[0][i] = new Card(currentCard.rank, currentCard.suit);
    if (currentCard.rank != 100) {
        this->listCard.remove(currentCard);
    }
    delete(currentCard);
}


void Player0036::TakeCards() {
    for (auto &j : Dealer::headTrick) {
        for (auto &i : j) {
            if (i != nullptr && i->rank != NOCARD && i->rank != PAS)
                this->TakeOneCard(i);
        }
    }
}

void Player0036::GetHeadTrick() {
    int i = Dealer::GetCurrentHeadTrik();

    Card byteCard = *Dealer::headTrick[0][i];
    Card currentCard = *new Card(100, 100);
    if (byteCard.rank > 99) return;
    if (i == Dealer::maxTrick || listCard.empty()) {
        currentCard.rank = NOCARD;
        Dealer::headTrick[1][i] = new Card(currentCard.rank, currentCard.suit);
        Dealer::addCurrentHeadTrik();
        return;
    }
    for (auto &it : this->listCard) {
        if ((it.suit == byteCard.suit) && (it.rank > byteCard.rank) && (it.rank < currentCard.rank)) {
            currentCard = it;
        }
    }
    if (currentCard.rank == 100) {
        for (auto &it : this->listCard) {
            if ((byteCard.suit != Dealer::GetTrump()->suit) &&
                (it.suit == Dealer::GetTrump()->suit) &&
                (it.rank < currentCard.rank)) {
                currentCard = it;
            }
        }
    }
    if (currentCard.rank == 100) {
        currentCard.rank = PAS;
    }

    Dealer::headTrick[1][i] = new Card(currentCard.rank, currentCard.suit);
    if (currentCard.rank != 100) {
        this->listCard.remove(currentCard);
    }
    Dealer::addCurrentHeadTrik();
}

void Player0036::ShowCards() {
    for (auto &it : this->listCard)
        cout << it.toString() << " ";
    std::cout << '\n';
}

void Player0036::TakeOneCard(Card *&nc) {
    if (nc->rank < 99)
        listCard.push_back(*nc);
}


bool Player0036::INeedCard() {
    return (listCard.size() < Dealer::maxTrick && Dealer::GetCard());
}

int Player0036::GetCardNum() {
    return static_cast<int>(listCard.size());
}


#define ALENA_PLAYER0036_H

#endif //ALENA_PLAYER0036_H
