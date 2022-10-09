#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "classes_Card_Deck.h"
#include "class_Hand.h"

void AI_cheat(Hand &ai_hand, Deck &plaing_deck)
{
    if (ai_hand.get_hand_power() < 21) {
        ai_hand.take_card(plaing_deck.topdeck());
        //Игра продолжается, ИИ берёт ещё одну карту

    }
    else
        ai_hand.set_player_status(2); //AI stoped
    
}

int main()
{
    setlocale(0, "");

    Deck first; //Создание игровой колоды
    first.shuffle(); //Мешается колода
    Hand player; //Создаётся пустая рука игрока
    Hand pc_opponent; //Создаётся рука ИИ_оппонента

    // Каждому игроку раздаются по 2 карты
    player.take_card(first.topdeck());
    pc_opponent.take_card(first.topdeck());
    player.take_card(first.topdeck());
    pc_opponent.take_card(first.topdeck());

    std::cout << "You hand is:" << '\n'; // Показ раздачи
    player.show_hand();

    while (player.get_player_status() != 2 && pc_opponent.get_player_status() != 2)
    {
        std::cout << "Do you want to take one more card?" << '\n'; //Начало игры
        std::cout << "1 - Yes" << '\n';
        std::cout << "2 - No" << '\n';
        unsigned short answer{ 0 }; // перменная, хранящая в себе ответ
        std::cin >> answer;

        if (answer == 1)
            player.take_card(first.topdeck());
        else
            player.set_player_status(2);

        player.show_hand();
        std::cout << player.get_hand_power() << '\n';
        AI_cheat(pc_opponent, first);//Решение ИИ

        std::cout << "## INFO: player_status " << player.get_player_status() << '\n';
        std::cout << "## INFO: pc_opponent_status " << pc_opponent.get_player_status() << '\n';

    }

    //Результат
    std::cout << "You score is: " << player.get_hand_power() << '\n';
    std::cout << "Opponent score is: " << pc_opponent.get_hand_power() << '\n';
    if (player.get_hand_power() > 21)
        if (pc_opponent.get_hand_power() <= 21)
            std::cout << "YOU LOSE!" << '\n';
        else 
            std::cout << "TIE!" << '\n';
    else
        if (pc_opponent.get_hand_power() <= 21)
            if (player.get_hand_power() > pc_opponent.get_hand_power())
                std::cout << "YOU WIN!!!" << '\n';
            else
                std::cout << "YOU LOSE!" << '\n';


}
