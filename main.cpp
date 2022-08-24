// ConsoleApplication1.cpp : Ýòîò ôàéë ñîäåðæèò ôóíêöèþ "main". Çäåñü íà÷èíàåòñÿ è çàêàí÷èâàåòñÿ âûïîëíåíèå ïðîãðàììû.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

const unsigned short DECK_SIZE = 52; // Êîëè÷åñòâî êàðò â êîëîäå
const unsigned short NUMBER_SIZE = 13; // Ðàçëè÷íûå íîìèíàëû êàðò
const unsigned short SUIT_SIZE = 4; // Ìàñòè


int main()
{
    std::cout << "Ðàáîòàåò òåñòîâàÿ âåðñèÿ ïðîãðàììû \"Áëåêäæåê\" (ïîêà ÷òî áåç øëþõ)\n";
    //setlocale(LC_ALL, "ru_RU");
    system("chcp 1251");

    class Card
    {
    public:
        Card(unsigned short int val = 2, unsigned short int su = 0)
        {
            value = val;
            suit = su;
        }
        ~Card()
        {
            //std::cout << "Destruct Card\t";
        }

        void show_card() //Âûâîä êàðòû íà ïå÷àòü. Ïå÷àòü ïðîèñõîäèò â ôîðìàòå çíà÷åíèå-ìàñòü. Ïðèìåð: JHeart, 10Clubs
        {
            if (value >= 2 and value <= 10) //Ïå÷àòü ñèëû êàðòû
                std::cout << value;
            else
            {
                switch (value)
                {
                    case 11:
                        std::cout << "J";
                        break;
                    case 12:
                        std::cout << "Q";
                        break;
                    case 13:
                        std::cout << "K";
                        break;
                    case 14:
                        std::cout << "A";
                        break;
                    default:
                        std::cout << "Error while printing VALUE_OF_CARD!\n";
                        break;
                }
            }

            switch (suit) // Ïå÷àòü ìàñòè
            {
                case 0:
                    std::cout << "Heart";
                    break;
                case 1:
                    std::cout << "Spades";
                    break;
                case 2:
                    std::cout << "Diamonds";
                    break;
                case 3:
                    std::cout << "Clubs";
                    break;
            }

            std::cout << std::endl;
        }

        unsigned short get_power()
        {
            return value;
        }

        Card operator=(const Card &oth_deck)
        {
            value = oth_deck.value;
            suit = oth_deck.suit;
            return* this;
        }

    private:
        unsigned short int value; // Ñèëà êàðòû. Îò 2óõ äî 14òè. 2 - 10 - îáû÷íàÿ ñèëà, 11 - Âàëåò, 12 - Äàìà, 13 - Êîðîëü, 14 - Òóç
        unsigned short int suit; // 0 - "Heart", 1 - "Spades", 2 - "Diamonds", 3 - "Clubs"
    };

    class Deck
    {
    public:

        Deck()
        {
            one_deck.resize(0);
            //std::cout << "Êîíñòðóòîð Äýêè" << std::endl;
            for (unsigned short v = 2; v < NUMBER_SIZE + 2; v++)
                for (unsigned short s = 0; s < SUIT_SIZE; s++)
                    one_deck.emplace_back(v, s);
            std::cout << "Äåêà ñôîðìèðîâàíà" << std::endl;

        }

        ~Deck()
        {
            //std::cout << "Ñðàáîòàë äåñòðóêòîð" << std::endl;
        }

        void show_deck()
        {
            for (unsigned short i = 0; i < DECK_SIZE; i++)
            {
                //std::cout << "i= " << i << "\t";
                one_deck[i].show_card();
            }
        }

        void shuffle()
        {
            std::cout << "Âûïîëíÿåòñÿ ïåðåìåøèâàíèå êîëîäû" << std::endl;
            std::shuffle(one_deck.begin(), one_deck.end(), std::default_random_engine {});

        }

        Card topdeck()
        {
            std::cout << "Âûäà÷à âåðõíåé êàðòû" << std::endl;
            Card dealer_hand = one_deck[one_deck.size()-1];
            one_deck.pop_back();
            //dealer_hand.show_card();
            return dealer_hand;
        }

    private:
        std::vector<Card> one_deck;
    };

    class Hand
    {
    public:
        Hand()
        {
            _hand.resize(0);
        }
        ~Hand()
        = default;
        void take_card(Card td)
        {
            _hand.emplace_back(td);
        }

        void show_hand()
        {
            std::cout << "Ðóêà èãðîêà:" << std::endl;
            for (unsigned short i = 0; i < _hand.size(); i++)
            {
                //std::cout << "i= " << i << "\t";
                _hand[i].show_card();
            }
        }

        unsigned short show_power()
        {
            unsigned short power_sum = 0;
            unsigned short count_a = 0;
            for (unsigned short i = 0; i < _hand.size(); i++)
            {
                if (_hand[i].get_power() == 14)
                    count_a += 1;
                else
                    power_sum += _hand[i].get_power();

                if (count_a == 2)
                    return 21;

            }
        }
    private:
        std::vector<Card> _hand;
    };


/*
    Card jh(14,2);
    jh.show_card();

    Card buf;
    buf.show_card();

*/
    //Card dealer_hand;
    Deck first;
    first.shuffle();
    Hand player;
    Hand pc_opponent;

    player.take_card(first.topdeck());
    pc_opponent.take_card(first.topdeck());
    player.take_card(first.topdeck());
    pc_opponent.take_card(first.topdeck());

    player.show_hand();

    //first.show_deck();
    //player.take_card(first.topdeck());
    //player.show_hand();

}

// Çàïóñê ïðîãðàììû: CTRL+F5 èëè ìåíþ "Îòëàäêà" > "Çàïóñê áåç îòëàäêè"
// Îòëàäêà ïðîãðàììû: F5 èëè ìåíþ "Îòëàäêà" > "Çàïóñòèòü îòëàäêó"

// Ñîâåòû ïî íà÷àëó ðàáîòû
//   1. Â îêíå îáîçðåâàòåëÿ ðåøåíèé ìîæíî äîáàâëÿòü ôàéëû è óïðàâëÿòü èìè.
//   2. Â îêíå Team Explorer ìîæíî ïîäêëþ÷èòüñÿ ê ñèñòåìå óïðàâëåíèÿ âåðñèÿìè.
//   3. Â îêíå "Âûõîäíûå äàííûå" ìîæíî ïðîñìàòðèâàòü âûõîäíûå äàííûå ñáîðêè è äðóãèå ñîîáùåíèÿ.
//   4. Â îêíå "Ñïèñîê îøèáîê" ìîæíî ïðîñìàòðèâàòü îøèáêè.
//   5. Ïîñëåäîâàòåëüíî âûáåðèòå ïóíêòû ìåíþ "Ïðîåêò" > "Äîáàâèòü íîâûé ýëåìåíò", ÷òîáû ñîçäàòü ôàéëû êîäà, èëè "Ïðîåêò" > "Äîáàâèòü ñóùåñòâóþùèé ýëåìåíò", ÷òîáû äîáàâèòü â ïðîåêò ñóùåñòâóþùèå ôàéëû êîäà.
//   6. ×òîáû ñíîâà îòêðûòü ýòîò ïðîåêò ïîçæå, âûáåðèòå ïóíêòû ìåíþ "Ôàéë" > "Îòêðûòü" > "Ïðîåêò" è âûáåðèòå SLN-ôàéë.
