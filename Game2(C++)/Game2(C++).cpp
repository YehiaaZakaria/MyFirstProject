// Game2(C++).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<map>
#include <iostream>
using namespace std;

char board[] = { '-', '-', '-',  '-',  '-',  '-',  '-',  '-',  '-'};
map <int, bool> taken;

void display_board()
{
    cout << board[0] << " | " << board[1] << " | " << board[2] << "       " << " 1 | 2 | 3 " << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << "       " << " 4 | 5 | 6 " << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << "       " << " 7 | 8 | 9 " << endl;

}

void add_even()
{
    cout << "Second player enter position from 1 to 9 :\n";
    while (true)
    {

        int position;
        cin >> position;
        position -= 1;
        if (position > 8 || position < 0)
        {
            cout << "please enter a valid position : \n";
        }
        else if (board[position] != '-')
        {
            cout << "this position is not valid \n";
        }
        else 
        {
            cout << "Second player please enter your number :\n";
            while (true) 
            {
                int even;
                cin >> even;
                if (even % 2 != 0 || even < 0 || even > 8)
                    cout << "Second player enter even number between 0 and 8 :\n";
                else if (taken[even])
                    cout << "the number is already taken, please enter another even number\n";
                else
                {
                    board[position] = even + '0';
                    taken[even] = true;
                    break;
                }
            }
            break;
        }
    }
}

void add_odd()
{
    cout << "First player enter position from 1 to 9 :\n";
    while (true)
    {
        int position;
        cin >> position;
        position -= 1;
        if (position > 8 || position < 0)
        {
            cout << "please enter a valid position : \n";
        }
        else if (board[position] != '-')
        {
            cout << "this position is not valid \n";
        }
        else
        {
            cout << "First player enter your number :\n";
            while (true)
            {
                
                int odd;
                cin >> odd;
                if (odd % 2 != 1 || odd < 1 || odd > 9)
                    cout << "please enter odd number between 1 and 9 :\n";
                else if (taken[odd])
                    cout << "the number is already taken, please eneter another odd number\n";
                else
                {
                    board[position] = odd +'0';
                    taken[odd] = true;
                    break;
                }
            }

            break;
            
        }

            }
}

bool check_diagonals() 
{
    bool game_over = false;
    if (board[0] != '-' && board[4] != '-' && board[8] != '-')
        if (board[0] - '0' + board[4] - '0' + board[8] - '0' == 15)
            game_over = true;

    if (board[2] != '-' && board[4] != '-' && board[6] != '-')
        if (board[2] - '0' + board[4] - '0' + board[6] - '0' == 15)
            game_over = true;
    return game_over;
}

bool check_columns()
{
    bool game_over = false;
    int i = 0;
    while (i < 3)
    {
        if (board[i] == '-' || board[i + 3] == '-' || board[i + 6] == '-')
            i += 1;
        else if (board[i] - '0' + board[i + 3] - '0' + board[i + 6] - '0' == 15)
        {
            game_over = true;
            break;
        }
        else
            i += 1;
    }
    return game_over;

}

bool check_rows()
{
    bool game_over = false;
    int i = 0;
    while (i < 7)
    {
        if (board[i] == '-' || board[i + 1] == '-' || board[i + 2] == '-')
            i += 3;
        else if (board[i] - '0' + board[i + 1] - '0' + board[i + 2] - '0' == 15)
        {
            game_over = true;
            break;
        }
        else
            i += 3;
    }
    return game_over;

}

bool check_draw()
{
    
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == '-')
            return false;
    }
    return true;

}

int main()
{
    for (int i = 0; i < 10; i++) {
        taken[i] = false;
    }
    display_board();
    while (true)
    {
        if (check_draw())
        {
            cout << " ---- A DRAW! ----\n";
            break;
        }

        add_odd();
        display_board();

        if (check_columns() == true || check_rows() == true || check_diagonals() == true) 
        {
            cout << " ---- First Player won! -----\n";
            break;
        }

        if (check_draw()) 
        {
            cout << "A DRAW!\n";
            break;
        }

        add_even();
        display_board();

        if (check_columns() == true || check_rows() == true || check_diagonals() == true)
        {
            cout << " ----- Second Player won! -----\n";
            break;
        }
    }
    return 0;
}

