// ===============================================
// Stone Paper Scissors (Professional Version)
// Template using Enums + Structs + Functions
// NOTE:
// This is a clean project skeleton showing the
// recommended architecture.
// ===============================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
enum enChoice{Stone=1,Paper=2,Scissors=3};
enum enWinner{Player=1,Computer=2,Draw=3};
struct stRoundInfo{short RoundNumber;enChoice PlayerChoice;enChoice ComputerChoice;enWinner Winner;};
struct stGameResults{short GameRounds=0;short PlayerWinTimes=0;short ComputerWinTimes=0;short DrawTimes=0;enWinner FinalWinner=Draw;};
short ReadRounds(){short Number;do{cout<<"Please Enter a Number 1 to 10 : ";cin>>Number;}while(Number<1||Number>10);return Number;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
enChoice ReadPlayerChoice(){short Choice;do{cout<<"Your Choice: [1] Stone, [2] Paper, [3] Scissors ? ";cin>>Choice;}while(Choice<1||Choice>3);return (enChoice)Choice;}
enChoice RandomComputerChoice(){return (enChoice)RandomNumbers(1,3);}
string ChoiceName(enChoice Choice){switch(Choice){case Stone:return "Stone";case Paper:return "Paper";default:return "Scissors";}}
string WinnerName(enWinner Winner){switch(Winner){case Player:return "Player";case Computer:return "Computer";default:return "Draw";}}
enWinner DecideWinner(enChoice PlayerChoice,enChoice ComputerChoice){if(PlayerChoice==ComputerChoice)return Draw;if((PlayerChoice==Stone&&ComputerChoice==Scissors)||(PlayerChoice==Paper&&ComputerChoice==Stone)||(PlayerChoice==Scissors&&ComputerChoice==Paper))return Player;return Computer;}
void ChangeScreenColor(enWinner Winner){switch(Winner){case Player:system("color 2F");break;case Computer:cout<<'\a';system("color 4F");break;case Draw:system("color 6F");break;}}
void RestartScreen(){system("cls");system("color 0F");}
stRoundInfo PlayRound(short RoundNumber){stRoundInfo Round;Round.RoundNumber=RoundNumber;cout<<"Round ["<<Round.RoundNumber<<"] begins: ";Round.PlayerChoice=ReadPlayerChoice();Round.ComputerChoice=RandomComputerChoice();Round.Winner=DecideWinner(Round.PlayerChoice,Round.ComputerChoice);ChangeScreenColor(Round.Winner);return Round;}
void PrintRoundResult(stRoundInfo Round){cout<<"\n----------- Round ["<<Round.RoundNumber<<"] -----------\n";cout<<"Player   : "<<ChoiceName(Round.PlayerChoice)<<endl;cout<<"Computer : "<<ChoiceName(Round.ComputerChoice)<<endl;cout<<"Winner   : ["<<WinnerName(Round.Winner)<<"]"<<endl;cout<<"---------------------------------------\n";}
stGameResults PlayGame(){stGameResults Game;Game.GameRounds=ReadRounds();for(short i=1;i<=Game.GameRounds;i++){stRoundInfo Round=PlayRound(i);PrintRoundResult(Round);switch(Round.Winner){case Player:Game.PlayerWinTimes++;break;case Computer:Game.ComputerWinTimes++;break;case Draw:Game.DrawTimes++;break;}}if(Game.PlayerWinTimes>Game.ComputerWinTimes)Game.FinalWinner=Player;else if(Game.ComputerWinTimes>Game.PlayerWinTimes)Game.FinalWinner=Computer;else Game.FinalWinner=Draw;return Game;}
void PrintGameResults(stGameResults Game){cout<<endl;cout<<"----------------------------------------------------------"<<endl;cout<<"\t\t*** G a m e  O v e r ***"<<endl;cout<<"----------------------------------------------------------"<<endl;cout<<"\t\t[Game Result]"<<endl;cout<<"Game Rounds   : "<<Game.GameRounds<<endl;cout<<"Player Wins   : "<<Game.PlayerWinTimes<<endl;cout<<"Computer Wins : "<<Game.ComputerWinTimes<<endl;cout<<"Draws         : "<<Game.DrawTimes<<endl;cout<<"Final Winner  : "<<WinnerName(Game.FinalWinner)<<endl;cout<<"----------------------------------------------------------"<<endl;}
bool PlayAgain(){char Answer;cout<<"\nPlay Again? (Y/N): ";cin>>Answer;return Answer=='Y'||Answer=='y';}
int main(){srand((unsigned)time(NULL));do{RestartScreen();stGameResults Game=PlayGame();PrintGameResults(Game);}while(PlayAgain());return 0;}
