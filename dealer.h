#pragma once

enum {
    PAS = 300, NOCARD = 400
};
//PAS - ������� �������� ���� (����� ������ ��� �����)
//NOCARD - ������� �������� ���� (��� ���� �� �����)

static const char *suits[] = {"Clubs", "Spades", "Hearts", "Diamonds"};
static const char *suitsSymb[] = {"\x5", "\x6", "\x3", "\x4"};
static const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

struct Card {
private:
    int suit;
    int rank;

    bool operator>(const Card &card);

    friend class Dealer;

    Card(int suit = -1, int rank = -1);

public:
    char *toString();

    bool operator==(const Card &rhs) const;

    bool operator!=(const Card &rhs) const;
};


class Dealer {
public:
    static const int maxSuits = 4;
    static const int maxRanks = 13;
    static const int maxTrick = 6;
    static const int allCard = 52;

private:
    static int currentCard;
    static Card *trump;  // ����� - ������
    static Card *noCard, *pasCard; // ����� - ������� "��� ����" � "���"

    static bool tableRanks[maxRanks];   // ����� ����, �������������� �� �����

    static int currentHeadTrik;                 //����� ���� � ����
    static Card *headTrick[2][maxTrick];        // ���� [0] - ��� ������, [1] - ����� �����
    static void GenerateDeck();


public:
    static Card deck[maxSuits * maxRanks]; //������

    //���������� ������ - �������������� ������ � ��� ����������.
    //�������� ������
    static void ShuffleDec();

    //����� ����� �� ������. ���������� true, ���� ����� ��� ��������.
    static bool GetCard(Card *&outCard);

    //���������� �������� ������ � ��������� Card (����� �������� ������ �����).
    static Card *GetTrump();

    // ���������� ����� �������� �� ������ ����
    static int getcurrentCard();

    //���������� ��������� �� ����
    static Card *(*GetheadTrick())[maxTrick];

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

bool Card::operator==(const Card &rhs) const {
    return suit == rhs.suit &&
           rank == rhs.rank;
}

bool Card::operator!=(const Card &rhs) const {
    return !(rhs == *this);
}

char *Card::toString() {
    char *result = "  ";

    return Card::rank+"  "+Card::suit +"\n";
}
