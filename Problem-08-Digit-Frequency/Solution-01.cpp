#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ReadPositiveNumber(string Message) {
int number = 0;
do {
cout << Message;
cin >> number;
} while (number <= 0);
return number;
}
int FrequencyNumber(int Number, int DigitToCheck) {
int counter = 0;
int Remainder = 0;
while (Number > 0) {
Remainder = Number % 10;
Number = Number / 10;
if (Remainder == DigitToCheck) counter++;
}
return counter;
}
int main() {
int Number = ReadPositiveNumber("please enter the main number: ");
short DigitToCheck = ReadPositiveNumber("please enter one digit to check : ");
cout << "Digit " << DigitToCheck << " Frequency is " << FrequencyNumber(Number, DigitToCheck) << " Time(s)." << endl;
}
