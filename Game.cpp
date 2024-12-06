#include "Game.h"
#include "Player.h"
#include "Board.h"

Game::Game()
{
    _num_players = 2;
}

Game::Game(Player character[], int num_players)
{

    if (num_players > 5 || num_players < 2)
    {
        _num_players = 2;
    }
    else
    {
        _num_players = num_players;
    }
}

void Game::loadCharacters()
{
    ifstream players("characters.txt");
    if (players.fail())
    {
        cout << "this shit does not work!!!" << endl;
    }

    string line;
    string name;
    string ageS;
    string staminaS;
    string wisdomS;
    string pridePointsS;
    int age;
    int stamina;
    int wisdom;
    int pridePoints;
    int idx = 0;

    while (getline(players, line) && idx < 5)
    {
        stringstream ss(line);
        getline(ss, name, '|');
        getline(ss, ageS, '|');
        getline(ss, staminaS, '|');
        getline(ss, wisdomS, '|');
        getline(ss, pridePointsS, '|');

        age = stoi(ageS);
        stamina = stoi(staminaS);
        wisdom = stoi(wisdomS);
        pridePoints = stoi(pridePointsS);

        // cout<<"Name: "<<name<<", Age: "<<age<<endl;
        // cout<<"Stamina: "<<stamina<<endl;
        // cout<<"Wisdom: "<<wisdom<<endl;
        // cout<<"Pride Points: "<<pridePoints<<endl;
        // cout<<"******************************"<<endl;

        _player[idx].setCharacter(name);
        _player[idx].setAge(age);
        _player[idx].setStamina(stamina);
        _player[idx].setWisdom(wisdom);
        _player[idx].setPridePoints(pridePoints);
        _player[idx].printStats();

        idx++;
    }
    players.close();
}

void Game::welcome()
{
    string name;
    int num_players;
    string character;
  

    cout << "Welcome to the Game of Life! Please enter how many people are playing and your name!" << endl;
    cout << "Number of People playing" << endl;
    cin >> num_players;
    cout << "    " << endl;
    for (int i = 0; i < num_players; i++)
    {

        cout << "Enter your name: ";
        cin >> name;
        cout << "   " << endl;

        loadCharacters();

        cout << "Choose a Character: ";
        cin >> character;
        cout << "   " << endl;

        if (character == "Apollo")
        {
            _player[0].setName(name);
            cout << "You chose Apollo!" << endl;
        }
        else if (character == "Mane")
        {
            _player[1].setName(name);
            cout << "You chose Mane!" << endl;
        }
        else if (character == "Elsa")
        {
            _player[2].setName(name);
            cout << "You chose Elsa!" << endl;
        }
        else if (character == "Zuri")
        {
            _player[3].setName(name);
            cout << "You chose Zuri!" << endl;
        }
        else if (character == "Roary")
        {
            _player[4].setName(name);
            cout << "You chose Roary!" << endl;
        }
        else
        {
            cout << "Choose a different Player." << endl;
        }
    }
}



// //void Game::menu()
// {
//     Board board;
//     int choice;
//     int i;
//     cout << "Main Menu: Select an option to continue" << endl;
//     cout << "1. Check Player Progress (1)" << endl;
//     cout << "2. Review Character (2)" << endl;
//     cout << "3. Check Position (3)" << endl;
//     cout << "4. Review your Advisor (4)" << endl;
//     cout << "5. Move Forward (5)" << endl;

//     cin >> choice;
//     switch (choice)
//     {
//     case 1:
//         _player[i].printStats();

//         break;
//     case 2:

//     case 3:
//        //board.getPlayerPosition();
//     case 4:

//     case 5:
//     }
// }

int main()
{
    Game game;
    game.welcome();
}
