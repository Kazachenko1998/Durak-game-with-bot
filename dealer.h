#pragma once

#include <string>

using namespace std;
enum {
    PAS = 300, NOCARD = 400
};
//PAS - ������� �������� ���� (����� ������ ��� �����)
//NOCARD - ������� �������� ���� (��� ���� �� �����)

static const char *suits[] = {"Clubs", "Spades", "Hearts", "Diamonds"};
static const char *suitsSymb[] = {"\x5", "\x6", "\x3", "\x4"};
static const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

class Card {


private:

    bool operator>(const Card &card);

    friend class Dealer;

public:
    int suit;
    int rank;

    Card(int rank, int suit) {
        this->rank = rank;
        this->suit = suit;
    };

    Card() {
        this->rank = -1;
        this->suit = -1;
    }

    std::string toString();

    bool operator==(const Card &rhs) const;

    bool operator!=(const Card &rhs) const;
};


class Dealer {
public:
    static const int maxSuits = 4;
    static const int maxRanks = 13;
    static const int maxTrick = 6;
    static const int allCard = maxSuits * maxRanks;
    static Card *headTrick[2][maxTrick];

private:
    static int currentCard;
    static Card *trump;  // ����� - ������
    static Card *noCard, *pasCard; // ����� - ������� "��� ����" � "���"
    static Card deck[52]; //������ ����

    static bool tableRanks[maxRanks];   // ����� ����, �������������� �� �����

    static int currentHeadTrik;                 //����� ���� � ����
    // ���� [0] - ��� ������, [1] - ����� �����
    static void GenerateDeck();


public:


//    static Card *(*getHeadTrick())[2][maxTrick]{
//        return *&Dealer::headTrick;
//    };
    //static Card *getHeadTrick()[];

    //���������� ������ - �������������� ������ � ��� ����������.
    //�������� ������
    static void ShuffleDec();

    //����� ����� �� ������. ���������� true, ���� ����� ��� ��������.
    static bool GetCard(Card *&outCard);

    static bool GetCard();


    //���������� �������� ������ � ��������� Card (����� �������� ������ �����).
    static Card *GetTrump();

    // ���������� ����� �������� �� ������ ����
    static int getCurrentCard();

    //���������� ��������� �� ����
    // static Card GetheadTrick()[maxTrick];
//    static Card *(GetheadTrick())[maxTrick];

    //���������� ��������� ������� ���������� ����� ��� ����������� �����
    static const char *SuitName(const Card *card);

    static const char *RankName(const Card *card);

    // * ���������� ������ ��������������� ����� ��� ����������� �����
    static int SuitIndex(const Card *card);

    static int RankIndex(const Card *card);

    // ���������� ����� ���� (0-5)
    static int GetCurrentHeadTrik();

    // ��������� �������� �� ��������� ��� (�����<6,������������ ����� �� ��������)
    static bool NextTrikEnable();

    // ��������� ����� � CurrentHeadTrik
    static void addCurrentHeadTrik();


    // * ������� �� ����� ����� ��� ����
    static void ShowCard(const Card *card);

    static void ShowTable();

    //* ���������� ��������� �� ����� "���" ��� "��� �����"
    static Card *GetPas();

    static Card *GetNocard();

    // ���������� ��������� �� ��������� ����� � ������� ������ � ������� ����������
    static Card *GetLastCard();

    static Card *GetLastDefendCard();

    //������� ����
    static void ClearTable();

    //��������� ����� �� ����� �� ������������
    static bool CheckHeadTrick();

    //��������� ������ ������ card
    static void Attack(Card *card);

    //������� ��������� �����, ������ card
    static void Defend(Card *card);

    ~Dealer();


};


