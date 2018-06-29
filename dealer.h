#pragma once

enum {
    PAS = 300, NOCARD = 400
};
//PAS - признак пропуска хода (нечем ходить или крыть)
//NOCARD - признак пропуска хода (нет карт на руках)

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
    static Card *trump;  // карта - козырь
    static Card *noCard, *pasCard; // карта - признак "нет карт" и "пас"

    static bool tableRanks[maxRanks];   // ранги карт, присутствующих на столе

    static int currentHeadTrik;                 //номер хода в кону
    static Card *headTrick[2][maxTrick];        // стол [0] - ход игрока, [1] - отбой карты
    static void GenerateDeck();


public:
    static Card deck[maxSuits * maxRanks]; //колода

    //перемешать колоду - инициализирует колоду и все переменные.
    //выбирает козыря
    static void ShuffleDec();

    //взять карту из колоды. возвращает true, если карты еще остались.
    static bool GetCard(Card *&outCard);

    //возвращает текущего козыря в структуре Card (имеет значение только масть).
    static Card *GetTrump();

    // возвращает число вышедших из колоды карт
    static int getcurrentCard();

    //возвращает указатель на стол
    static Card *(*GetheadTrick())[maxTrick];

    //возвращает строковый литерал содержащий масть или достоинство карты
    static const char *SuitName(const Card *card);

    static const char *RankName(const Card *card);

    // * возвращает индекс соответствующий масти или достоинству карты
    static int SuitIndex(const Card *card);

    static int RankIndex(const Card *card);

    // возвращает номер хода (0-5)
    static int GetCurrentHeadTrik();

    // Проверяет возможен ли следующий ход (ходов<6,отбивающийся игрок не спасовал)
    static bool NextTrikEnable();


    // * выводит на экран карту или стол
    static void ShowCard(const Card *card);

    static void ShowTable();

    //* возвращает указатель на карту "пас" или "нет карты"
    static Card *GetPas();

    static Card *GetNocard();

    // возвращает указатель на последнюю карту с которой ходили и которой отбивались
    static Card *GetLastCard();

    static Card *GetLastDefendCard();


    //очищает стол
    static void ClearTable();

    //проверяет карты на столе на корректность
    static bool CheckHeadTrick();

    //атаковать игрока картой card
    static void Attack(Card *card);

    //покрыть атакующую карту, картой card
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
