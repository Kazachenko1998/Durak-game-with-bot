#pragma once

class PlayerAbstract {
protected:


public:
    virtual ~PlayerAbstract();

    //получает признак "мой ход"
    virtual void YouTurn(bool) = 0;

    //игрок кладёт карту на стол (headTrick[0][*])
    virtual void PutCard() = 0;

    // забирает все карты со стола
    virtual void TakeCards() = 0;

    // отбивает карту (кладёт карту в (headTrick[1][*])
    virtual void GetHeadTrick() = 0;

    //взял одну карту
    virtual void TakeOneCard(Card *&nc) = 0;

    // вывел свои карты на экран ранг (один/два символа, масть - символ)
    virtual void ShowCards() = 0;

    // возвращает истину, если на руках карт меньше 6
    virtual bool INeedCard() = 0;

    // возвращает число карт на руках
    virtual int GetCardNum() = 0;
};

PlayerAbstract::~PlayerAbstract() {

}



