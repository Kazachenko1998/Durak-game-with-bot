#include "dealer.h"

#pragma comment(lib, "dealer.lib")

#include "player0036.h"
//#include <vld.h>

#include <iostream>


int main() {

    int p1win = 0, p2win = 0, drawn = 0;
    for (int count = 0; count < 100; count++) {
        Dealer::ShuffleDec();
        for (int i = 0; i < Dealer::allCard; ++i) {
            cout<<Dealer::deck[i];
        }
        Card *temp;
        Player0036 p1("Konstantin");
        Player0036 p2("Grigory   ");


        p1.ShowCards();

        PlayerAbstract *player1;
        PlayerAbstract *player2;
        PlayerAbstract *tmp;

        if (count % 2) {
            p1.YouTurn(true);
            p2.YouTurn(false);
            player1 = &p1;
            player2 = &p2;

        } else {
            p1.YouTurn(false);
            p2.YouTurn(true);
            player1 = &p2;
            player2 = &p1;

        }

        //	Player *player = p2;

        while (player1->INeedCard()) {
            Dealer::GetCard(temp);
            player1->TakeOneCard(temp);
        }
        while (player2->INeedCard()) {
            Dealer::GetCard(temp);
            player2->TakeOneCard(temp);
        }

        int triknum = 1;
        while ((player1->GetCardNum() && player2->GetCardNum()) || Dealer::getcurrentCard() < 52) {
            std::cout << triknum++ << ":" << std::endl;
            while (player1->INeedCard()) {
                Dealer::GetCard(temp);
                player1->TakeOneCard(temp);
            }
            while (player2->INeedCard()) {
                Dealer::GetCard(temp);
                player2->TakeOneCard(temp);
            }

            player1->ShowCards();
            player2->ShowCards();
            while (Dealer::NextTrikEnable()) {
                //player1->ShowCards();
                //player2->ShowCards();

                player1->PutCard();
                //Dealer::ShowTable();
                player2->GetHeadTrick();
                //Dealer::ShowTable();
            }
            Dealer::ShowTable();
            int kht = Dealer::GetCurrentHeadTrik();
            // проверить всё по парам
            if (Dealer::CheckHeadTrick()) // карты отбиты верно
            {
                Card *plastDefCard = Dealer::GetLastDefendCard();
                Card *plastCard = Dealer::GetLastCard();
                if (plastDefCard != NULL) {
                    // если последня карта отбоя  "пас" - второй забирает карты себе
                    if (Dealer::RankIndex(plastDefCard) == PAS) {
                        player2->TakeCards();
                        Dealer::ClearTable();
                    }
                        // если последняя карта с которой ходили - пас или нет карт - переход хода, отбой
                    else if ((Dealer::RankIndex(plastCard) == PAS) ||
                             (Dealer::RankIndex(plastCard) == NOCARD) ||
                             (Dealer::GetCurrentHeadTrik() == 6)
                            ) {
                        Dealer::ClearTable();
                        player2->YouTurn(true);
                        player1->YouTurn(false);
                        tmp = player2;
                        player2 = player1;
                        player1 = tmp;
                    }
                }
            } else {
                std::cout << "error";
            }
        }

        if (!player1->GetCardNum() && !player2->GetCardNum()) {
            drawn++;
            std::cout << "\ndrawn game\n";
        } else if (!player1->GetCardNum()) {
            std::cout << "\np1 - win\n";
            if (player1 == &p1)
                p1win++;
            else
                p2win++;
        } else if (!player2->GetCardNum()) {
            std::cout << "\np2 - win\n";
            if (player2 == &p2)
                p2win++;
            else
                p1win++;
        }

        // если последняя катра - пас - второй забирает

        player1->ShowCards();
        player2->ShowCards();

        std::cout << "\nKonstantin - " << p1win << " Grigory - " << p2win << " drawn " << drawn;
    }


    return 0;
}
