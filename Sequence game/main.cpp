//This project is created by Muhammad Ammar 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//  STRUCTURES 
struct Player
{
    int score;
    int chances;
};

struct Question
{
    int series[6];
    int answer;
};

//  DRAWING 
void drawPlayer()
{
    cout << "  O\n";
    cout << " /|\\\n";
    cout << " / \\\n";
}

void drawMonster(int distance)
{
    for (int i = 0; i < distance; i++) cout << " ";
    cout << "####\n";
    for (int i = 0; i < distance; i++) cout << " ";
    cout << "#  #\n";
    for (int i = 0; i < distance; i++) cout << " ";
    cout << "####\n";
}

//  QUESTIONS 
void generateLevel1(Question* q)
{
    int start = rand() % 5 + 2;
    int diff = rand() % 4 + 1;
    int miss = rand() % 6;

    for (int i = 0; i < 6; i++)
        q->series[i] = start + i * diff;

    q->answer = q->series[miss];
    q->series[miss] = -1;
}

void generateLevel2(Question* q) {
    int type = rand() % 3;
    int miss = rand() % 6;

    if (type == 0)
    { // squares
        for (int i = 0; i < 6; i++)
            q->series[i] = (i + 1) * (i + 1);
    }
    else if (type == 1)
    { // alternating
        int a = 2, b = 3;
        for (int i = 0; i < 6; i++)
            q->series[i] = (i % 2 == 0) ? a += 2 : b += 3;
    }
    else
    { // mixed multiply
        q->series[0] = 2;
        for (int i = 1; i < 6; i++)
            q->series[i] = q->series[i - 1] * 2;
    }

    q->answer = q->series[miss];
    q->series[miss] = -1;
}

void generateLevel3(Question* q, int pattern)
{
    int miss = rand() % 6;

    if (pattern == 0)
    { // quadratic sequence
        int a = 1;
        for (int i = 0; i < 6; i++)
            q->series[i] = a += i * 2;
    }
    else if (pattern == 1)
    { // multiply + add
        q->series[0] = 3;
        for (int i = 1; i < 6; i++)
            q->series[i] = q->series[i - 1] * 2 + 1;
    }
    else if (pattern == 2)
    { // prime numbers
        int primes[6] = { 2, 3, 5, 7, 11, 13 };
        for (int i = 0; i < 6; i++)
            q->series[i] = primes[i];
    }
    else if (pattern == 3)
    { // fibonacci variation
        q->series[0] = 1;
        q->series[1] = 2;
        for (int i = 2; i < 6; i++)
            q->series[i] = q->series[i - 1] + q->series[i - 2] + 1;
    }
    else if (pattern == 4)
    { // square & cube alternating
        for (int i = 0; i < 6; i++)
            q->series[i] = (i % 2 == 0) ? (i + 2) * (i + 2) : (i + 2) * (i + 2) * (i + 2);
    }
    else if (pattern == 5)
    { // arithmetic + geometric mix
        q->series[0] = 2;
        for (int i = 1; i < 6; i++)
            q->series[i] = q->series[i - 1] * 2 - 1;
    }
    else
    { // double previous + index
        q->series[0] = 4;
        for (int i = 1; i < 6; i++)
            q->series[i] = q->series[i - 1] * 2 + i;
    }

    q->answer = q->series[miss];
    q->series[miss] = -1;
}


void showQuestion(Question* q)
{
    cout << "Series Question:\n";
    for (int i = 0; i < 6; i++) {
        if (q->series[i] == -1) cout << " ? ";
        else cout << q->series[i] << " ";
    }
    cout << endl;
}

//  MAIN 

int main()
{
    srand(time(0));
    Player player;
    player.score = 0;
    player.chances = 2;

    int monsterDistance = 25;

    cout << "===== THE SEQUENCE STRIKES =====\n";

    //  LEVEL 1 
    cout << "\n----- LEVEL 1 -----\n";

    for (int q = 1; q <= 3; q++)
    {
        Question qu;
        generateLevel1(&qu);

        cout << "\n_____________________________\n" << "\nQuestion " << q << endl;
        drawPlayer();
        drawMonster(monsterDistance);
        showQuestion(&qu);

        int userAns;
        cout << "Enter Answer: ";
        cin >> userAns;

        if (userAns == qu.answer)
        {
           
            player.score += 10;
        }
        else
        {
            cout << "Wrong! -5\n";
            player.score -= 5;
            monsterDistance -= 15;
            player.chances--;
        }

        cout << "SCORE: " << player.score << endl;

        if (player.chances <= 0)
        {
            cout << "\nMONSTER CAUGHT YOU!\nGAME OVER\n";
            cout << "Final Score: " << player.score;

            return 0;
        }
    }

    // NEXT LEVEL 
    char choice;
    cout << "\nLevel 1 Complete!\nGo to Level 2? (y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        cout << "Game Ended.\nFinal Score: " << player.score;
        return 0;
    }

    // -------- LEVEL 2 --------
    cout << "\n_____________________________\n" << "\n----- LEVEL 2 -----\n";
    player.chances = 2;
    monsterDistance = 25;

    for (int q = 1; q <= 5; q++)
    {
        Question qu;
        generateLevel2(&qu);

        cout << "\nQuestion " << q << endl;
        drawPlayer();
        drawMonster(monsterDistance);
        showQuestion(&qu);

        int userAns;
        cout << "Enter Answer: ";
        cin >> userAns;

        if (userAns == qu.answer)
        {
         
            player.score += 10;
        }
        else
        {
            cout << "Wrong! -5\n";
            player.score -= 5;
            monsterDistance -= 15;
            player.chances--;
        }

        cout << "SCORE: " << player.score << endl;

        if (player.chances <= 0)
        {
            cout << "\nMONSTER CAUGHT YOU!\nGAME OVER\n";
            cout << "Final Score: " << player.score;

            return 0;
        }
    }

    
    
    // NEXT LEVEL
    cout << "\nLevel 2 Complete!\nGo to Level 3? (y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y')
    {
        cout << "Game Ended.\nFinal Score: " << player.score;
        return 0;
    }

    // -------- LEVEL 3 --------
    cout << "\n_____________________________\n";
    cout << "----- LEVEL 3 (HARD) -----\n";

    player.chances = 2;
    monsterDistance = 25;

    for (int q = 1; q <= 7; q++)
    {
        Question qu;
        generateLevel3(&qu, q - 1);   // ensures all 7 patterns are different

        cout << "\nQuestion " << q << endl;
        drawPlayer();
        drawMonster(monsterDistance);
        showQuestion(&qu);

        int userAns;
        cout << "Enter Answer: ";
        cin >> userAns;

        if (userAns == qu.answer)
        {
           
            player.score += 15;
        }
        else
        {
            cout << "Wrong! -10\n";
            player.score -= 10;
            monsterDistance -= 15;
            player.chances--;
        }

        cout << "SCORE: " << player.score << endl;

        if (player.chances <= 0)
        {
            cout << "\nMONSTER CAUGHT YOU!\nGAME OVER\n";
            cout << "Final Score: " << player.score;
            return 0;
        }
    }
    //  END 
    cout << "\n YOU COMPLETED ALL LEVELS \n";
    cout << "Final Score: " << player.score << endl;

    return 0;
}