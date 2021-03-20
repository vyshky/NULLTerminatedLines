#include<iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;


void InputLine(char str[], const int n);
int StrLen(char str[]);

bool is_mac_address(char str[]);
bool is_ip_address(char str[]);

void to_upper(char str[]);//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр

void capitalize(char str[]);//Первую букву каждого слова в предложении делает заглавной

void shrink(char str[]);	//Убирает из строки лишние пробелы

bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом
bool is_int_number(char str[]); //Определяет, является ли строка целым числом, то есть, состоит только из цифр

__int64 to_int_numer(char str[]); //Если строка является числом, то функция возвращает значение этого числа

void remove_sumbol(char str[], char sumbol);

int is_bin_number(char str[]);
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
	cout << "Является ли строка IP-адресом : " << is_ip_address(arr) << endl;

	cout << arr << endl;
	cout << "Проверяет, является ли строка MAC-адресом : " << is_mac_address(arr) << endl;




	return 0;
}


void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251 принимает только в этой кодировке
	SetConsoleCP(866);
	cout << str << endl;//CP866
}

int StrLen(char str[])
{
	int count = 0;
	for (int i = 0; str[i]; i++)
	{
		count++;
	}
	return count;
}

bool is_mac_address(char str[])
{
	int count_dot = 0;
	int count_number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] == '.' || str[i] == '-' || str[i] == ':'))count_number++;

		if (count_number == 3)return 0;

		if (i < 1 && (str[i] == '.' || str[i] == '-' || str[i] == ':'))	return 0;

		if (str[i] == '.' || str[i] == '-' || str[i] == ':')
		{
			count_dot++;
			count_number = 0;
		}
	}
	if (count_dot != 5) return false;

	for (int i = 0; str[i]; i++)
	{
		int weight = 1;
		int count = 0;
		for (int j = i; j < i + 2 && str[j] != 0; j++)
		{
			if (str[j] >= 'a' && str[j] <= 'f')
			{
				count += (str[j] - 87) * weight;
				weight *= 16;
			}
			else if (str[j] != '.' && str[j] != '-' && str[j] != ':' && str[j] >= '0' && str[j] <= '9')
			{
				count *= 10;
				count += str[j] - 48;
			}
			if (count > 255) return false;
		}
	}
	return true;
}

bool is_ip_address(char str[])
{
	int count_dot = 0;
	int count_number = 0;

	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] == '.'))count_number++;
		if (str[i] == '.')
		{
			count_dot++;
			count_number = 0;
		}
		if (count_number > 3)return 0;

	}
	if (count_dot != 3)return false;

	for (int i = 0; str[i]; i++)
	{
		int count = 0;
		for (int j = i; j < i + 3; j++)
		{
			if (str[j] != '.' && str[j] >= '0' && str[j] <= '9')
			{
				count *= 10;
				count += str[j] - 48;
			}
			if (count > 255)return false;
		}
	}
	return true;
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
	for (int i = 0, count = 0; str[i]; i++, count++)
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

	for (int i = 0; i <= count; i++)
	{
		if (str[i] != str[count - i])	return false;

	}
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return false;

		if (str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

__int64 to_int_numer(char str[])
{
	if (!is_int_number(str)) return 0;
	__int64 number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			number *= 10; // Сдвигаем число на 1 разряд в лево , чтобы освободить младший разряд для следующее цифры
			number += str[i] - 48;// 48 в ASCII-код символ '0'
		}
	}
	return number;
}

void remove_sumbol(char str[], char sumbol)
{
	for (int i = 0; i < str[i]; i++)
	{
		if (str[i] == sumbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

int is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1])return false;
	}
	return true;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int decimal = 0;
	int weight = 1;
	int n = strlen(str);
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;
}

int hex_to_dec(char str[])
{
	int count = StrLen(str);
	to_lower(str);

	int decimal = 0;
	int weight = 1;

	for (int i = count - 1; i >= 0; i--)
	{
		if (!(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= '0' && str[i] <= '9'))	return 0;
		if (str[i] >= '0' && str[i] <= '9' && str[i] != ' ')decimal += (str[i] - 48) * weight;
		if (str[i] >= 'a' && str[i] <= 'f' && str[i] != ' ')decimal += (str[i] - 87) * weight;
		weight *= 16;
	}
	return decimal;
}

