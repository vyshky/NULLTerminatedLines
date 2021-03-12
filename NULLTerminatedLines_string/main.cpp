#include<iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;


void InputLine(char str[], const int n);

void to_upper(char str[]);//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр

void capitalize(char str[]);//Первую букву каждого слова в предложении делает заглавной

void shrink(char str[]);	//Убирает из строки лишние пробелы

bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом
bool is_int_number(char str[]); //Определяет, является ли строка целым числом, то есть, состоит только из цифр

int to_int_numer(char str[]); //Если строка является числом, то функция возвращает значение этого числа

int  bin_to_dec(char str[]); //Если строка является двоичным числом, то функция возвращает его десятичное значение
int  hex_to_dec(char str[]);	//Если строка является шестнадцатеричным числом, то функция возвращает его десятичное значение


int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 100;
	char arr[n];
	cout << "Введите строку : ";

	InputLine(arr, n);

	to_upper(arr);
	cout << arr << endl;

	to_lower(arr);
	//cout << arr << endl;

	//capitalize(arr);
	//cout << arr << endl;

	shrink(arr);
	cout << arr << endl;

	cout << "Палиндром? " << is_palindrome(arr) << endl;
	cout << "Строчка является числом? " << is_int_number(arr) << endl;
	cout << "Если строка является числом, то функция возвращает значение этого числа : " << to_int_numer(arr) << endl;
	cout << "Если строка является двоичным числом, то функция возвращает его десятичное значение : " << bin_to_dec(arr) << endl;
	cout << "Если строка является шестнадцатеричным числом, то функция возвращает его десятичное значение : " << hex_to_dec(arr) << endl;




	return 0;
}


void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251 принимает только в этой кодировке
	SetConsoleCP(866);
	cout << str << endl;//CP866
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 97 && str[i] <= 122)str[i] -= 32;	       //из a-z   в    A-Z	
		else if (str[i] >= -32 && str[i] <= -1)str[i] -= 32;   //из a-я   в    A-Я		
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)str[i] += 32;         //из A-Z    в     a-z		
		else if (str[i] >= -65 && str[i] <= -33)str[i] += 32;  //из А-Я    в     а-я		
	}
}

void capitalize(char str[])
{
	if (str[0] >= 97 && str[0] <= 122)str[0] -= 32;           //Первую букву из a-z   в    A-Z	
	else if (str[0] >= -32 && str[0] <= -1)str[0] -= 32;      //Первую букву из a-я   в    A-Я
}

void shrink(char str[])
{
	for (int i = 0, count = i; str[i]; i++, count++)
	{
		while (str[count] == 32 && str[count + 1] == 32)
		{
			count++;
		}
		str[i] = str[count];
	}
}

bool is_palindrome(char str[])
{
	int count = 0;
	for (int i = 1; str[i]; i++)
	{
		count += sizeof(str[0]);
	}
	for (int i = 0; i <= count; i++, count--)
	{
		if (str[i] == str[count]);
		else
		{
			return 0;
		}
	}
	return 1;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 75 || str[i] >= 97 && str[i] <= 102);
		else
		{
			return 0;
		}
	}
	return 1;
}

int to_int_numer(char str[])
{
	int number = is_int_number(str);
	if (number == 0)return 0;
	else
	{
		number = 0;
		int key = 0;
		for (int i = 0; str[i]; i++)
		{
			switch (str[i])
			{
			case '0':key = 0; break;
			case '1':key = 1; break;
			case '2':key = 2; break;
			case '3':key = 3; break;
			case '4':key = 4; break;
			case '5':key = 5; break;
			case '6':key = 6; break;
			case '7':key = 7; break;
			case '8':key = 8; break;
			case '9':key = 9; break;
			}
			number += key;
			number *= 10;
		}
	}
	return number / 10;
}

int bin_to_dec(char str[])
{
	int number = to_int_numer(str);
	int buffer;
	int sum = 0;


	for (int i = 0; number != 0; i++)
	{
		if (number % 10 > 1)return 0;
		buffer = 2;

		if (number % 10 == 0)
		{
			number /= 10;
			continue;
		}

		if (i == 0)	buffer = 1;

		for (int j = i; j > 1; j--)	buffer *= 2;

		number /= 10;
		sum += buffer;
	}
	return sum;
}

int hex_to_dec(char str[])
{
	int buffer = 0, number = 0, sum = 0;

	int i = 0;

	for (; str[i] != '\0'; i++) {}
	i--;

	for (int i2 = 0; str[i] >= 0; i--, i2++)
	{
		buffer = 16;
		if (i2 == 0)	buffer = 1;
		for (int j = i2; j > 1; j--)	buffer *= 16;

		switch (str[i])
		{
		case '0':number = 0; break;
		case '1':number = 1; break;
		case '2':number = 2; break;
		case '3':number = 3; break;
		case '4':number = 4; break;
		case '5':number = 5; break;
		case '6':number = 6; break;
		case '7':number = 7; break;
		case '8':number = 8; break;
		case '9':number = 9; break;
		case 'A':number = 10; break;
		case 'B':number = 11; break;
		case 'C':number = 12; break;
		case 'D':number = 13; break;
		case 'E':number = 14; break;
		case 'F':number = 15; break;
		case 'a':number = 10; break;
		case 'b':number = 11; break;
		case 'c':number = 12; break;
		case 'd':number = 13; break;
		case 'e':number = 14; break;
		case 'f':number = 15; break;
		}

		if (number >= 10 && number <= 15) buffer *= number;
		else if (number >= 0 && number <= 9) buffer *= number;

		sum += buffer;
	}

	return sum;
}

