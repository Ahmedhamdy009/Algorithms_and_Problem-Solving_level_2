#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enQuestionsLevel{Easy=1,Med=2,Hard=3,Mix=4};
enum enOperationType{Add=1,Sub=2,Mul=3,Div=4,MixOp=5};
short ReadHowManyQuestions(){short Number=0;do{cout<<"How Many Questions do you want to answer ? ";cin>>Number;}while(Number<1||Number>10);return Number;}
enQuestionsLevel ReadQuestionsLevel(){short Choice;do{cout<<"Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";cin>>Choice;}while(Choice<1||Choice>4);return (enQuestionsLevel)Choice;}
enOperationType ReadOperationType(){short Choice;do{cout<<"Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] MixOp ? ";cin>>Choice;}while(Choice<1||Choice>5);return (enOperationType)Choice;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
enOperationType GetRandomOperationType(){return (enOperationType)RandomNumbers(1,4);}
string GetOpTypeSymbol(enOperationType OpType){string a[5]={"+","-","*","/","Mix"};return a[OpType-1];}
string GetQuestionLevelText(enQuestionsLevel QuestionLevel){string a[4]={"Easy","Medium","Hard","Mixed"};return a[QuestionLevel-1];}
int SimpleCalculator(int Number1,int Number2,enOperationType OperationType){switch(OperationType){case Add:return Number1+Number2;case Sub:return Number1-Number2;case Mul:return Number1*Number2;case Div:return Number2!=0?Number1/Number2:0;default:return Number1+Number2;}}
void GenerateQuestion(enQuestionsLevel QuestionLevel,enOperationType OperationType,int &Number1,int &Number2,enOperationType &QuestionOperation,int &CorrectAnswer){if(QuestionLevel==Mix)QuestionLevel=(enQuestionsLevel)RandomNumbers(1,3);if(OperationType==MixOp)OperationType=GetRandomOperationType();QuestionOperation=OperationType;switch(QuestionLevel){case Easy:Number1=RandomNumbers(1,10);Number2=RandomNumbers(1,10);break;case Med:Number1=RandomNumbers(10,50);Number2=RandomNumbers(10,50);break;case Hard:Number1=RandomNumbers(50,100);Number2=RandomNumbers(50,100);break;default:break;}if(QuestionOperation==Div)Number1*=Number2;CorrectAnswer=SimpleCalculator(Number1,Number2,QuestionOperation);}
void PrintQuestion(int Number1,int Number2,enOperationType QuestionOperation){cout<<"\n"<<Number1<<"\n"<<GetOpTypeSymbol(QuestionOperation)<<"\n"<<Number2<<"\n____________________\n";}
int ReadPlayerAnswer(){int PlayerAnswer;cout<<"Your Answer: ";cin>>PlayerAnswer;return PlayerAnswer;}
bool CheckAnswer(int PlayerAnswer,int CorrectAnswer){return PlayerAnswer==CorrectAnswer;}
void ChangeScreenColor(bool IsCorrect){if(IsCorrect)system("color 2F");else system("color 4F");}
void ResetScreen(){system("color 0F");system("cls");}
void PrintQuestionResult(bool IsCorrect,int CorrectAnswer){if(IsCorrect)cout<<"Right Answer :-)"<<endl;else cout<<"Wrong Answer :-(\nThe right answer is : "<<CorrectAnswer<<endl;cout<<endl;}
void PrintFinalResults(short HowManyQuestions,short RightAnswers,short WrongAnswers,enQuestionsLevel QuestionLevel,enOperationType OperationType){bool Pass=RightAnswers>=WrongAnswers;cout<<"\n=================================\nFinal Results\n=================================\n";cout<<"Number of Questions : "<<HowManyQuestions<<endl;cout<<"Question Level      : "<<GetQuestionLevelText(QuestionLevel)<<endl;cout<<"Operation Type      : "<<GetOpTypeSymbol(OperationType)<<endl;cout<<"Right Answers       : "<<RightAnswers<<endl;cout<<"Wrong Answers       : "<<WrongAnswers<<endl;cout<<"Final Results is    : "<<(Pass?"Yes :-)":"No :- (")<<endl;}
void PlayGame(){short HowManyQuestions=ReadHowManyQuestions();enQuestionsLevel QuestionLevel=ReadQuestionsLevel();enOperationType OperationType=ReadOperationType();short RightAnswers=0,WrongAnswers=0;for(short QuestionNumber=1;QuestionNumber<=HowManyQuestions;QuestionNumber++){int Number1,Number2,CorrectAnswer,PlayerAnswer;enOperationType QuestionOperation;cout<<"\nQuestion ["<<QuestionNumber<<"/"<<HowManyQuestions<<"]\n\n";GenerateQuestion(QuestionLevel,OperationType,Number1,Number2,QuestionOperation,CorrectAnswer);PrintQuestion(Number1,Number2,QuestionOperation);PlayerAnswer=ReadPlayerAnswer();bool IsCorrect=CheckAnswer(PlayerAnswer,CorrectAnswer);ChangeScreenColor(IsCorrect);PrintQuestionResult(IsCorrect,CorrectAnswer);if(IsCorrect)RightAnswers++;else WrongAnswers++;}PrintFinalResults(HowManyQuestions,RightAnswers,WrongAnswers,QuestionLevel,OperationType);}
void StartGame(){char PlayAgain='Y';do{ResetScreen();PlayGame();cout<<"\nDo you want to play again? [Y/N] ";cin>>PlayAgain;}while(PlayAgain=='Y'||PlayAgain=='y');}
int main(){srand((unsigned)time(NULL));StartGame();return 0;}
