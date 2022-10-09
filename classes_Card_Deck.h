#pragma once

const unsigned short DECK_SIZE = 52;	// Количество карт в колоде
const unsigned short NUMBER_SIZE = 13;	// Различные номиналы карт
const unsigned short SUIT_SIZE = 4;	// Масти

class Card
{
public:
    Card(unsigned short int val = 2, unsigned short int su = 0)
    {
        _value = val;
        _suit = su;
    }
    ~Card()
    {
        //std::cout << "Destruct Card\t";
    }

    void show_card() {	//Вывод карты на печать. Печать происходит в формате значение-масть. Пример: JHeart, 10Clubs
        if (_value >= 2 and _value <= 10)	//Печать силы карты
            std::cout << _value;
        else
        {
            switch (_value)
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

        switch (_suit) // Печать масти
        {
        case 0:
            std::cout << "\u2665 " << "Heart";
            break;
        case 1:
            std::cout << "\u2660 " << "Spades";
            break;
        case 2:
            std::cout << "\u2666 " << "Diamonds";
            break;
        case 3:
            std::cout << "\u2663 " << "Clubs";
            break;
        }

        std::cout << std::endl;
    }

    unsigned short get_power()
    {
        if (_value < 11)
            return _value;
        else if (_value == 14)
            return 11;
        else
            return 10;
    }

    Card operator=(const Card& oth_deck)
    {
        _value = oth_deck._value;
        _suit = oth_deck._suit;
        return*this;
    }

private:
    unsigned short int _value; // Сила карты. От 2ух до 14ти. 2 - 10 - обычная сила, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз
    unsigned short int _suit; // 0 - "Heart", 1 - "Spades", 2 - "Diamonds", 3 - "Clubs"
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
        std::shuffle(one_deck.begin(), one_deck.end(), std::default_random_engine{});

    }

    Card topdeck()
    {
        std::cout << "Взятие верхней карты" << std::endl;
        Card dealer_hand = one_deck[one_deck.size() - 1];
        one_deck.pop_back();
        //dealer_hand.show_card();
        return dealer_hand;
    }

private:
    std::vector<Card> one_deck;
};


