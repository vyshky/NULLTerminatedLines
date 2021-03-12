#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);


int main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = { 'H','e','l','l','o' , 0 };
	/*char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str);*/

	const	int n = 20;
	char str[n] = "";
	cout << "¬ведите строку : ";
	//cin >> str;
	InputLine(str, n);
	cout << endl << StrLen(str) << endl;
	return 0;
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << str;//CP866
}

int StrLen(char str[])
{
	int i = 0;	
	for (; str[i] != '\0'; i++)
	//for (; str[i]; i++); 
	return i;
}
