/*
=================================== ⚙️ ﷽ ===================================
  [PROJECT] │ #51 - Stone, Paper, Scissors Game Engine (Refactored Core)
  ----------|---------------------------------------------------------------
  [CONTEXT] │ Course: Algorithms & Problem Solving Level 2
  ----------|---------------------------------------------------------------
  [AUTHOR]  │
  ----------|---------------------------------------------------------------
  [DATE]    │
  ----------|---------------------------------------------------------------
  [DESC]    │ Fully optimized version resolving dynamic return layout omissions,
  ----------| fixing conditional precedence traps, and tuning UI flash frequencies.
===========================================================================
*/
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
enum enChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};

enum enWinner
{
    Player = 1,
    Computer = 2,
    Draw = 3
};

struct stRoundInfo
{
    short RoundNumber;
    enChoice PlayerChoice;   // للاعب
    enChoice ComputerChoice; // للكمبيوتر
    enWinner Winner;         // للفوز
};

struct stGameResults
{
    short GameRound = 0;        // عدد الجولات
    short PlayerWinTimes = 0;   // عدد فوز اللعب
    short ComputerWinTimes = 0; // عدد فوز الكمبيوتر
    short DrawTimes = 0;        // عدد التعادل
    enWinner FinalWinner = Draw;
};

short ReadRound() // لادخال الرقم
{
    short Number = 0;
    do
    {
        cout << "Please Enter a Number 1 to 10 : ";
        cin >> Number;
    } while (Number < 1 || Number > 10);

    return Number;
}

int RandomNumbers(int From, int To) // للرقم العشوائي هيكون للكمبيوتر
{
    int RandomNumbers = From + rand() % (To - From + 1);
    return RandomNumbers;
}

enChoice ReadPlayerChoice() // لاختيار اللاعب
{
    short Choice;
    do
    {
        cout << "Your Choice: [1] Stone, [2] Paper, [3] Scissors ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enChoice)Choice;
}

enChoice RandomComputerChoice() // لاختيار الكمبيوتر
{
    return (enChoice)RandomNumbers(1, 3);
}

string ChoiceName(enChoice Choice)
{
    switch (Choice)
    {
    case Stone:
        return "Stone";

    case Paper:
        return "Paper";

    default:
        return "Scissors";
    }
}

string WinnerName(enWinner Winner)
{
    switch (Winner)
    {
    case Player:
        return "Player";

    case Computer:
        return "Computer";

    default:
        return "Draw";
    }
}

enWinner DecideWinner(enChoice PlayerChoice, enChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
        return Draw;

    if ((PlayerChoice == Stone && ComputerChoice == Scissors) ||
        (PlayerChoice == Paper && ComputerChoice == Stone) ||
        (PlayerChoice == Scissors && ComputerChoice == Paper))
        return Player;

    return Computer;
}

void ChangeScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case Player:
        system("color 2F");
        break;

    case Computer:
        cout << "\a";
        system("color 4F");
        break;

    case Draw:
        system("color 6F");
        break;
    }
}

void RestartScreen()
{
    system("cls");
    system("color 0F");
}

stRoundInfo PlayRound(short RoundNumber) // PlayRound(i)
{
    stRoundInfo Round;
    Round.RoundNumber = RoundNumber; // ل short RoundNumber
    cout << "Round [" << Round.RoundNumber << "] begins: ";
    Round.PlayerChoice = ReadPlayerChoice();                               // من دي ل CompterChoice(ChoiceName)
    Round.ComputerChoice = RandomComputerChoice();                         // من دي ل PlayerChoice(ChoiceName)
    Round.Winner = DecideWinner(Round.PlayerChoice, Round.ComputerChoice); // من دي ل PrintRoundResult(Winner)

    ChangeScreenColor(Round.Winner);
    return Round;
}

void PrintRoundResult(stRoundInfo Round)
{
    cout << "\n-----------Round [" << Round.RoundNumber << "] -----------\n";
    cout << "Player   : " << ChoiceName(Round.PlayerChoice) << endl;
    cout << "Computer   : " << ChoiceName(Round.ComputerChoice) << endl;
    cout << "Winner   : [" << WinnerName(Round.Winner) << "]" << endl;
    cout << "---------------------------------------\n";
}
stGameResults PlayGame()
{
    stGameResults Game;
    Game.GameRound = ReadRound();
    for (short i = 1; i <= Game.GameRound; i++)
    {
        stRoundInfo Round = PlayRound(i); // دي هتودي علي (short RoundNumber) (1 , 10)
        PrintRoundResult(Round);          // هناخد من PlayRound  نودي ل PrintRoundResult
        // دي كل شغلها انها تطبع بس وتعرض البيانات

        switch (Round.Winner)
        {
        case Player:
            Game.PlayerWinTimes++;
            break;
        case Computer:
            Game.ComputerWinTimes++;
            break;
        case Draw:
            Game.DrawTimes++;
            break;
        }
    }
    if (Game.PlayerWinTimes > Game.ComputerWinTimes)
        Game.FinalWinner = Player;

    else if (Game.ComputerWinTimes > Game.PlayerWinTimes)
        Game.FinalWinner = Computer;

    else
        Game.FinalWinner = Draw;

    return Game;
}
void PrintGameResults(stGameResults Game)
{
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "\t\t*** G a m e  O v e r ***" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "\t\t[Game Result]" << endl;

    cout << "Game Rounds   : " << Game.GameRound << endl;
    cout << "Player Wins   : " << Game.PlayerWinTimes << endl;
    cout << "Computer Wins : " << Game.ComputerWinTimes << endl;
    cout << "Draws         : " << Game.DrawTimes << endl;
    cout << "Final Winner  : " << WinnerName(Game.FinalWinner) << endl;
    cout << "----------------------------------------------------------" << endl;
}
bool PlayAgain()
{
    char Answer;
    cout << "\nPlay Again? (Y/N): ";
    cin >> Answer;

    return (Answer == 'Y' || Answer == 'y');
}
void StartGame()
{
    do
    {
        RestartScreen();
        stGameResults Game = PlayGame();
        PrintGameResults(Game);
    } while (PlayAgain());
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}