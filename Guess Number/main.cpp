#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int number_level( int num)
{

    cout << "entre the level\n";
    cout << "easy press 1 , medium press 2 ,hard press 3\n";
    cin >> num;
    return num;
}
int number_random()
{
    return rand() % (100 - 1 + 1) + 1;
}
int number_user(int &num)
{
    cout << "entre the number\n";
    cin >> num;
    return num;
}
void ply(int num1,int num2)
{

    if (num1 == num2)
    {
        cout << "your guess is correct\n";
        system("color 2F");// to make a console green

    }
    if (num1> num2)
    {
        cout << "your guess larger than number\n";
        system("color 4F");// to make a console red
    }
    if (num1< num2)
    {
        cout << "your guess is smaller than number\n";
        system("color 4F");// to make a console red
    }
}
void game( int &num1,int& num2,int& num_level)
{

    num_level= number_level(num_level);
    if (num_level == 1)
    {
        num2=number_random();
        for (int i = 0; i < 9; i++)
        {
            num1 = number_user(num1);
            ply(num1, num2);
            if (num1 == num2)
            {
                break;
            }
        }
        cout << "the number is " << num2<<"\n";
    }
    if (num_level == 2)
    {
        num2 = number_random();
        for (int i = 0; i < 6; i++)
        {
            num1 = number_user(num1);
            ply(num1, num2);
            if (num1 == num2)
            {
                break;
            }
        }
        cout << "the number is " << num2 << "\n";

    }
    if (num_level == 3)
    {
        num2 = number_random();
        for (int i = 0; i < 5; i++)
        {
            num1 = number_user(num1);
            ply(num1, num2);
            if (num1 == num2)
            {
                break;
            }
        }
        cout << "the number is " << num2 << "\n";

    }
}
void headerOfGame()
{
    system("color 0F");
    cout << "\t\t\t\t\twelcome to the guess number game\n";
    cout << "you have to guess a number between 1 and 100. ";
    cout << " you will have a limited choices on the level ";
    cout << "you choose. good luck\n";
}

void guessNumberGame(int& num1, int& num2, int& num_level)
{
    char return_game;

    headerOfGame();
    game(num1, num2, num_level);
    cout << "Do you want to play again?\n";
    cout << "if you need press 'y' else press 'n' \n";
    cin >> return_game;
    if (return_game == 'y'|| return_game == 'Y')
    {
        guessNumberGame(num1, num2, num_level);
    }

}
int main()
{
    srand(time(0));
    int num1, num2, num_level;
    guessNumberGame(num1, num2, num_level);
}
