#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enQuestionsLevel {Easy=1,Med=2,Hard=3,Mix=4};
enum enOperationType {Add=1,Sub=2,Mul=3,Div=4,MixOp=5};
const short MaxQuestions=10;
struct stQuestion{int Number1;int Number2;enQuestionsLevel QuestionLevel;enOperationType OperationType;int CorrectAnswer=0;int PlayerAnswer=0;bool AnswerResult=false;};
struct stQuiz{stQuestion QuestionList[MaxQuestions];short NumberOfQuestion;enQuestionsLevel QuestionLevel;enOperationType OperationType;short NumberOfRightAnswer=0;short NumberOfWrongAnswer=0;bool isPass=false;};
short ReadHowManyQuestions(){short Number=0;do{cout<<"How Many Questions do you want to answer ? ";cin>>Number;}while(Number<1||Number>MaxQuestions);return Number;}
enQuestionsLevel ReadQuestionsLevel(){short Choice;do{cout<<"Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";cin>>Choice;}while(Choice<1||Choice>4);return (enQuestionsLevel)Choice;}
enOperationType ReadOperationType(){short Choice;do{cout<<"Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] MixOp ? ";cin>>Choice;}while(Choice<1||Choice>5);return (enOperationType)Choice;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
enOperationType GetRandomOperationType(){return (enOperationType)RandomNumbers(1,4);}
string GetOpTypeSymbol(enOperationType OpType){string a[5]={"+","-","*","/","Mix"};return a[OpType-1];}
string GetQuestionLevelText(enQuestionsLevel QuestionLevel){string a[4]={"Easy","Medium","Hard","Mixed"};return a[QuestionLevel-1];}
void ChangeScreenColor(bool Right){if(Right)system("color 2F");else system("color 4F");}
void ResetScreen(){system("color 0F");system("cls");}
int SimpleCalculator(int Number1,int Number2,enOperationType OperationType){switch(OperationType){case Add:return Number1+Number2;case Sub:return Number1-Number2;case Mul:return Number1*Number2;case Div:return Number2!=0?Number1/Number2:0;default:return Number1+Number2;}}
stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel,enOperationType OperationType){stQuestion Question;if(QuestionLevel==Mix)QuestionLevel=(enQuestionsLevel)RandomNumbers(1,3);if(OperationType==MixOp)OperationType=GetRandomOperationType();Question.OperationType=OperationType;Question.QuestionLevel=QuestionLevel;switch(QuestionLevel){case Easy:Question.Number1=RandomNumbers(1,10);Question.Number2=RandomNumbers(1,10);break;case Med:Question.Number1=RandomNumbers(10,50);Question.Number2=RandomNumbers(10,50);break;case Hard:Question.Number1=RandomNumbers(50,100);Question.Number2=RandomNumbers(50,100);break;default:Question.Number1=RandomNumbers(1,10);Question.Number2=RandomNumbers(1,10);break;}if(Question.OperationType==Div)Question.Number1*=Question.Number2;Question.CorrectAnswer=SimpleCalculator(Question.Number1,Question.Number2,Question.OperationType);return Question;}
void GenerateQuizQuestion(stQuiz &Quiz){for(short Question=0;Question<Quiz.NumberOfQuestion;Question++)Quiz.QuestionList[Question]=GenerateQuestion(Quiz.QuestionLevel,Quiz.OperationType);}
int ReadPlayerAnswer(){int Answer;cout<<"Your Answer: ";cin>>Answer;return Answer;}
void PrintTheQuestion(stQuiz &Quiz,short QuestionNumber){cout<<"\nQuestion["<<QuestionNumber+1<<"/"<<Quiz.NumberOfQuestion<<"]\n"<<Quiz.QuestionList[QuestionNumber].Number1<<"\n"<<GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OperationType)<<"\n"<<Quiz.QuestionList[QuestionNumber].Number2<<"\n----------------\n";}
void CorrectTheQuestionAnswer(stQuiz &Quiz,short QuestionNumber){if(Quiz.QuestionList[QuestionNumber].PlayerAnswer==Quiz.QuestionList[QuestionNumber].CorrectAnswer){Quiz.QuestionList[QuestionNumber].AnswerResult=true;Quiz.NumberOfRightAnswer++;cout<<"Right Answer :) ";}else{Quiz.QuestionList[QuestionNumber].AnswerResult=false;Quiz.NumberOfWrongAnswer++;cout<<"Wrong Answer :( The Right Answer is : "<<Quiz.QuestionList[QuestionNumber].CorrectAnswer<<endl;}cout<<endl;ChangeScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);}
string GetFinalResult(bool Pass){return Pass?"Pass :)":"Fail :(";}
void PrintFinalResults(stQuiz Quiz){cout<<"\n=================================\nFinal Results is "<<GetFinalResult(Quiz.isPass)<<endl<<"=================================\n";cout<<"Number of Questions : "<<Quiz.NumberOfQuestion<<endl<<"Question Level      : "<<GetQuestionLevelText(Quiz.QuestionLevel)<<endl<<"Operation Type      : "<<GetOpTypeSymbol(Quiz.OperationType)<<endl<<"Right Answers       : "<<Quiz.NumberOfRightAnswer<<endl<<"Wrong Answers       : "<<Quiz.NumberOfWrongAnswer<<endl<<"=========================================================\n";}
void AskAndCorrectQuestionListAnswers(stQuiz &Quiz){for(short QuestionNumber=0;QuestionNumber<Quiz.NumberOfQuestion;QuestionNumber++){PrintTheQuestion(Quiz,QuestionNumber);Quiz.QuestionList[QuestionNumber].PlayerAnswer=ReadPlayerAnswer();CorrectTheQuestionAnswer(Quiz,QuestionNumber);}Quiz.isPass=(Quiz.NumberOfRightAnswer>=Quiz.NumberOfWrongAnswer);}
void PlayGame(){stQuiz Quiz;Quiz.NumberOfQuestion=ReadHowManyQuestions();Quiz.QuestionLevel=ReadQuestionsLevel();Quiz.OperationType=ReadOperationType();GenerateQuizQuestion(Quiz);AskAndCorrectQuestionListAnswers(Quiz);PrintFinalResults(Quiz);}
void StartGame(){char PlayAgain='Y';do{ResetScreen();PlayGame();cout<<"\nDo you want to play again? [Y/N] ";cin>>PlayAgain;}while(PlayAgain=='Y'||PlayAgain=='y');}
int main(){srand((unsigned)time(NULL));StartGame();return 0;}
