#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

const unsigned short DECK_SIZE = 52;	// Количество карт в колоде
const unsigned short NUMBER_SIZE = 13;	// Различные номиналы карт
const unsigned short SUIT_SIZE = 4;	// Масти


int main()
{
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

        void show_card() {	//Вывод карты на печать. Печать происходит в формате значение-масть. Пример: JHeart, 10Clubs
            if (value >= 2 and value <= 10)	//Печать силы карты
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

            switch (suit) // Печать масти
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
        unsigned short int value; // Сила карты. От 2ух до 14ти. 2 - 10 - обычная сила, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз
        unsigned short int suit; // 0 - "Heart", 1 - "Spades", 2 - "Diamonds", 3 - "Clubs"
    };

    class Deck
    {
    public:

        Deck()
        {
            one_deck.resize(0);
            //std::cout << "Конструктор Дэки" << std::endl;
            for (unsigned short v = 2; v < NUMBER_SIZE + 2; v++)
                for (unsigned short s = 0; s < SUIT_SIZE; s++)
                    one_deck.emplace_back(v, s);
            std::cout << "Дэка построена" << std::endl;

        }

        ~Deck()
        {
            //std::cout << "Деструктор дэки отработал" << std::endl;
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
            std::cout << "Выполняется перемешивание колоды" << std::endl;
            std::shuffle(one_deck.begin(), one_deck.end(), std::default_random_engine {});

        }

        Card topdeck()
        {
            std::cout << "Взятие верхней карты" << std::endl;
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
            std::cout << "Карты в руке:" << std::endl;
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
