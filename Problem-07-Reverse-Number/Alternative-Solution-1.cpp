#include <iostream>
#include <string>
using namespace std;
int ReadNumber(string message)
{
	int number;
	do 
	{
		cout << message << endl;
		cin >> number;
	} while (number <= 0);

	return number;
}

void PrintInOrder(int number)
{
	string num = to_string(number);
	for (int i = 0; i < num.length(); i++)
	{
		cout << num[i] << endl;

	}
}

 
int main() {
	int number = ReadNumber("Enter the big number?\n");

	PrintInOrder(number);
	 
	return 0;
}
