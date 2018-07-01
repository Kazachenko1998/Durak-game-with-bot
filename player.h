#pragma once

class PlayerAbstract {
protected:


public:
    virtual ~PlayerAbstract();

    //�������� ������� "��� ���"
    virtual void YouTurn(bool) = 0;

    //����� ����� ����� �� ���� (headTrick[0][*])
    virtual void PutCard() = 0;

    // �������� ��� ����� �� �����
    virtual void TakeCards() = 0;

    // �������� ����� (����� ����� � (headTrick[1][*])
    virtual void GetHeadTrick() = 0;

    //���� ���� �����
    virtual void TakeOneCard(Card *&nc) = 0;

    // ����� ���� ����� �� ����� ���� (����/��� �������, ����� - ������)
    virtual void ShowCards() = 0;

    // ���������� ������, ���� �� ����� ���� ������ 6
    virtual bool INeedCard() = 0;

    // ���������� ����� ���� �� �����
    virtual int GetCardNum() = 0;
};

PlayerAbstract::~PlayerAbstract() {

}



