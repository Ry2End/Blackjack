class Hand
{
public:
    Hand()
    {
        _hand.resize(0);
        _status = 1 ;
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

    unsigned short get_hand_power() // Подсчёт очков руки игрока
    {
        unsigned short power_sum = 0;
        unsigned short count_A_card = 0;
        if (_hand[0].get_power() == 14 && _hand[1].get_power() == 14) // BlackJack with two "A" cards
            return 21;
        for (unsigned short i = 0; i < _hand.size(); i++)
        {
            if (_hand[i].get_power() == 14) {
                count_A_card += 1;
                power_sum += _hand[i].get_power();
            }
            else
                power_sum += _hand[i].get_power();

            if (power_sum > 21 && count_A_card > 0) { // count "A" card downgrade to 1 if power_sum > 21
                power_sum = power_sum - 10;
                count_A_card -= 1;
            }



        }
        return power_sum;
    }

    void set_player_status(unsigned short set_status) //Задать статус игрока. Планируется для проверки состояния партии: 1 - игра продолжается, 2 - игрок перестал набирать карты, открылся. Очки <=21. 3 - игрок проиграл, очки > 21
    {
        this->_status = set_status;
    }
    unsigned short get_player_status() 
    {
        return this->_status;
    }

private:
    std::vector<Card> _hand;
    short unsigned _status;
};

