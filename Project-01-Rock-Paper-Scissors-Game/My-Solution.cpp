#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
enum enChoice{Stone=1,Paper=2,Scissors=3};
enum enUsers{Player=1,Computer=2,Draw=3};
int CountMyWin=0,CountMyComputer=0,CountDraw=0;
int ReadPositiveNumber(){int Number=0;do{cout<<"Please Enter a Number 1 to 10 : ";cin>>Number;}while(Number<1||Number>10);return Number;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
string GetChoiceName(enChoice Choice){switch(Choice){case Stone:return "Stone";case Paper:return "Paper";case Scissors:return "Scissors";default:return "Invalid Choice ";}}
enChoice MyChoice(){int choice;do{cout<<"Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";cin>>choice;}while(choice<1||choice>3);return (enChoice)choice;}
enChoice MyComputer(){return (enChoice)RandomNumbers(1,3);}
void ChangeScreenColor(enUsers Winner){switch(Winner){case Player:system("color 2F");break;case Computer:system("color 4F");cout<<"\a";break;case Draw:system("color 6F");break;default:break;}}
string GetWinnerName(enUsers User){switch(User){case Player:return "Player";case Computer:return "Computer";case Draw:return "Draw";default:return "Invalid Choice ";}}
enUsers GameRules(enChoice MyChoice,enChoice computer){if(MyChoice==computer){CountDraw++;return Draw;}if((MyChoice==Stone&&computer==Scissors)||(MyChoice==Paper&&computer==Stone)||(MyChoice==Scissors&&computer==Paper)){CountMyWin++;return Player;}CountMyComputer++;return Computer;}
void RestartScreen(){system("color 0F");system("cls");}
void PrintResultsForRound(int NumberOfRounds){for(int i=1;i<=NumberOfRounds;i++){cout<<"Round ["<<i<<"] begins: ";enChoice PlayerChoice=MyChoice();enChoice ComputerChoice=MyComputer();cout<<"---------------Round ["<<i<<"]--------------"<<endl;cout<<"Player Choice: "<<GetChoiceName(PlayerChoice)<<endl;cout<<"Computer Choice: "<<GetChoiceName(ComputerChoice)<<endl;enUsers Winner=GameRules(PlayerChoice,ComputerChoice);ChangeScreenColor(Winner);cout<<"Round Winner : ["<<GetWinnerName(Winner)<<"]"<<endl;if(i!=NumberOfRounds)cout<<"----------------------------------"<<endl;}}
void PrintResults(int round){cout<<endl<<"----------------------------------------------------------"<<endl<<"\t\t*** G a m e  O v e r ***"<<endl<<"----------------------------------------------------------"<<endl<<"\t\t[Game Result]"<<endl;cout<<"Game Rounds        : "<<round<<endl;cout<<"Player Won Times   : "<<CountMyWin<<endl;cout<<"Computer Won Times : "<<CountMyComputer<<endl;cout<<"Draw Times         : "<<CountDraw<<endl;if(CountMyComputer>CountMyWin)cout<<"Final Winner       : Computer"<<endl;else if(CountMyWin>CountMyComputer)cout<<"Final Winner       : Player"<<endl;else cout<<"Final Winner       : Draw"<<endl;cout<<"----------------------------------------------------------"<<endl;}
char PlayAgain(){char Answer;cout<<"Do you want to play again? Y/N? ";cin>>Answer;return Answer;}
int main(){srand((unsigned)time(NULL));char Answer;do{CountMyWin=0;CountMyComputer=0;CountDraw=0;RestartScreen();int Number=ReadPositiveNumber();PrintResultsForRound(Number);PrintResults(Number);}while(PlayAgain());return 0;}
