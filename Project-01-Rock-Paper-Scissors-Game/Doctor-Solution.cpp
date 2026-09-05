#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enChoice{Stone=1,Paper=2,Scissors=3};
enum enWinner{Player=1,Computer=2,Draw=3};
struct stRoundInfo{short RoundNumber=0;enChoice PlayerChoice;enChoice ComputerChoice;enWinner Winner;};
struct stGameResults{short GameRound=0;short PlayerWinTimes=0;short ComputerWinTimes=0;short DrawTimes=0;enWinner GameWinner;};
short ReadRound(){short Number=0;do{cout<<"Please Enter a Number 1 to 10 : ";cin>>Number;}while(Number<1||Number>10);return Number;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
enChoice ReadPlayerChoice(){short Choice;do{cout<<"Your Choice: [1] Stone, [2] Paper, [3] Scissors ? ";cin>>Choice;}while(Choice<1||Choice>3);return (enChoice)Choice;}
enChoice RandomComputerChoice(){return (enChoice)RandomNumbers(1,3);}
string ChoiceName(enChoice Choice){string a[3]={"Stone","Paper","Scissors"};return a[Choice-1];}
string WinnerName(enWinner Winner){string a[3]={"Player","Computer","No Winner (Draw)"};return a[Winner-1];}
enWinner DecideWinner(stRoundInfo RoundInfo){if(RoundInfo.PlayerChoice==RoundInfo.ComputerChoice)return Draw;switch(RoundInfo.PlayerChoice){case Stone:return RoundInfo.ComputerChoice==Paper?Computer:Player;case Paper:return RoundInfo.ComputerChoice==Scissors?Computer:Player;case Scissors:return RoundInfo.ComputerChoice==Stone?Computer:Player;}return Draw;}
enWinner WhoWinTheGame(short PlayerWinTimes,short ComputerWinTimes){if(PlayerWinTimes>ComputerWinTimes)return Player;if(ComputerWinTimes>PlayerWinTimes)return Computer;return Draw;}
void ChangeScreenColor(enWinner Winner){switch(Winner){case Player:system("color 2F");break;case Computer:cout<<"\a";system("color 4F");break;case Draw:system("color 6F");break;}}
void ResetScreen(){system("cls");system("color 0F");}
string Tabs(short tabs){string t="";for(int i=0;i<tabs;i++)t+="\t";return t;}
void ShowGameOverScreen(){cout<<"\n\n"<<Tabs(1)<<"----------------------------------------------------------------\n"<<Tabs(1)<<"              ++ +G a m e O v e r++ +\n"<<Tabs(1)<<"----------------------------------------------------------------\n";}
stGameResults FillGameResults(int GameRound,short PlayerWinTimes,short ComputerWinTimes,short DrawTimes){stGameResults GameResult;GameResult.GameRound=GameRound;GameResult.PlayerWinTimes=PlayerWinTimes;GameResult.ComputerWinTimes=ComputerWinTimes;GameResult.DrawTimes=DrawTimes;GameResult.GameWinner=WhoWinTheGame(PlayerWinTimes,ComputerWinTimes);return GameResult;}
void PrintRoundResult(stRoundInfo RoundInfo){cout<<"\n-----------Round ["<<RoundInfo.RoundNumber<<"] -----------\n";cout<<"Player Choice : "<<ChoiceName(RoundInfo.PlayerChoice)<<endl;cout<<"Computer Choice : "<<ChoiceName(RoundInfo.ComputerChoice)<<endl;cout<<"Round Winner : ["<<WinnerName(RoundInfo.Winner)<<"]"<<endl<<"---------------------------------------\n";}
stGameResults PlayGame(short HowManyRound){stRoundInfo RoundInfo;short PlayerWinTimes=0,ComputerWinTimes=0,DrawTimes=0;for(short GameRound=1;GameRound<=HowManyRound;GameRound++){cout<<"\nRound ["<<GameRound<<"] begins: ";RoundInfo.RoundNumber=GameRound;RoundInfo.PlayerChoice=ReadPlayerChoice();RoundInfo.ComputerChoice=RandomComputerChoice();RoundInfo.Winner=DecideWinner(RoundInfo);if(RoundInfo.Winner==Player)PlayerWinTimes++;else if(RoundInfo.Winner==Computer)ComputerWinTimes++;else DrawTimes++;ChangeScreenColor(RoundInfo.Winner);PrintRoundResult(RoundInfo);}return FillGameResults(HowManyRound,PlayerWinTimes,ComputerWinTimes,DrawTimes);}
void ShowFinalGameResults(stGameResults GameResult){cout<<Tabs(1)<<"------------------------ [Game Result] --------------------------------- \n";cout<<Tabs(1)<<"Game Rounds : "<<GameResult.GameRound<<endl;cout<<Tabs(1)<<"player 1 won times : "<<GameResult.PlayerWinTimes<<endl;cout<<Tabs(1)<<"computer won times : "<<GameResult.ComputerWinTimes<<endl;cout<<Tabs(1)<<"draw times : "<<GameResult.DrawTimes<<endl;cout<<Tabs(1)<<"FinalWinner : "<<WinnerName(GameResult.GameWinner)<<endl;cout<<Tabs(1)<<"------------------------------------------------------------------------";}
void StartGame(){char PlayAgain='Y';do{ResetScreen();stGameResults GameResults=PlayGame(ReadRound());ShowGameOverScreen();ShowFinalGameResults(GameResults);cout<<endl<<Tabs(4)<<"Do you Want to Play again? (Y/N): ";cin>>PlayAgain;}while(PlayAgain=='Y'||PlayAgain=='y');}
int main(){srand((unsigned)time(NULL));StartGame();return 0;}
