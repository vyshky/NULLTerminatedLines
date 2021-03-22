#include<iostream>
#include <Windows.h>
//#include <conio.h>
#include <ctype.h>
using namespace std;

void InputLine(char str[], const int n);
void to_upper(char str[]);//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void capitalize(char str[]);//Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);	//Убирает из строки лишние пробелы
bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом
bool is_int_number(char str[]); //Определяет, является ли строка целым числом, то есть, состоит только из цифр
long long int to_int_numer(char str[]); //Если строка является числом, то функция возвращает значение этого числа
void remove_sumbol(char str[], char sumbol);
bool is_mac_address(char str[]);
bool is_ip_address(char str[]);
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
	cout << arr << endl;

	remove_sumbol(arr, 'q');
	cout << arr << endl;

	shrink(arr);
	cout << arr << endl;

	/*capitalize(arr);
	cout << arr << endl;*/

	cout << "Палиндром? " << (is_palindrome(arr) ? " ДА" : " НЕТ") << endl;

	cout<< "Это число ?" << (is_int_number(arr) ? " ДА : " : "___________не число___________ ") << to_int_numer(arr) << endl;

	cout << "Является ли строка IP-адресом : " << (is_ip_address(arr) ? " ДА" : "___________не IP___________") << endl;

	cout << "Проверяет, является ли строка MAC-адресом : " << (is_mac_address(arr) ? " ДА" : "___________не MAC___________") << endl;

	cout << (hex_to_dec(arr) ? " " : "___________не шестнадцатеричное___________") << endl;
	cout << (bin_to_dec(arr) ? " " : "________________не двоичное_______________") << endl;

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
		str[i] = toupper(str[i]);
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		str[i] = tolower(str[i]);
	}
}

void capitalize(char str[])
{
	//	if (str[0] >= 97 && str[0] <= 122) str[0] = toupper(str[0]);           //Первую букву из a-z   в    A-Z	
	//	else if (str[0] >= -32 && str[0] <= -1) str[0] = toupper(str[0]);      //Первую букву из a-я   в    A-Я	
	str[0] = toupper(str[0]);           //Первую букву из a-z   в    A-Z	//Первую букву из a-я   в    A-Я
}

void shrink(char str[])
{
	for (int i = 0, count = 0; str[i]; i++, count++)
	{
		//while (str[count] == ' ' && str[count + 1] == ' ')
		while (isblank(str[count]) && isblank(str[count + 1]))
		{
			count++;
		}
		str[i] = str[count];
	}
}

bool is_palindrome(char str[])
{
	int count = strlen(str);
	count--;
	for (int i = 0; i < count; i++)
	{
		if (str[i] != str[count - i])	return false;
	}
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(isxdigit(str[i])) && str[i] != ' ')
			return false;

		if (isblank(str[i]) && isblank(str[i + 1]))
			return false;
	}	
	return true;
}

long long int to_int_numer(char str[])
{
	if (!is_int_number(str)) return 0;
	long long int number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (isxdigit(str[i]) && !isdigit(str[i]))
		{
			number = strtoull(str, NULL, 16);
			break;
		}

		if (!isblank(str[i]))
		{
			number *= 10; // Сдвигаем число на 1 разряд в лево , чтобы освободить младший разряд для следующее цифры
			number += str[i] - 48;// 48 в ASCII-код символ '0'
		}
	}	
	return number;
}

void remove_sumbol(char str[], char sumbol)
{
	for (int i = 0, count = 0; i < str[i]; i++, count++)
	{
		while (str[count] == sumbol)
		{
			count++;
		}
		str[i] = str[count];
	}
}
int bin_to_dec(char str[])
{
	int count = strlen(str);					//Стандартная функция библиотеки <iostream> - вычисляет количество символов в строке

	long int number = strtol(str, NULL, 2);	//Стандартная функция библиотеки <cstdlib>  - преобразовать строку в длинное целое число 

	for (int i = count - 1; i; i--)
	{
		if (!(str[i] < '2' && str[i] >= '0'))   //Проверьте, является ли символ десятичным числом
		{
			return 0;
		}
	}
	cout << "Двоичное число число " << str << " %bin : " << number << " %dec ";
	return 1;
}

int hex_to_dec(char str[])
{
	int count = strlen(str);					//Стандартная функция библиотеки <iostream>
	for (int i = count - 1; i; i--)
	{
		if (!isxdigit(str[i]))                  //Определяет , является ли число 16 - ричным
		{
			return 0;
		}
	}
	long int number = strtol(str, NULL, 16);	//Стандартная функция библиотеки <cstdlib>
	cout << "Шестнадцатеричное число " << str << " %hex : " << number << " %dec ";
	return 1;
}


bool is_mac_address(char str[])
{
	int count_dot = 0, sum = 0, count_number = 0, weight = 1;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] != '.' && str[i] != '-' && str[i] != ':') && !isxdigit(str[i]))	return false;
		if (str[i] != '.' && isxdigit(str[i]))	count_number++;
		if (str[i] == '.' || str[i] == '-' || str[i] == ':')
		{
			count_dot++;
			count_number = 0;
			sum = 0;
			weight = 1;
		}
		if (count_number != 2)return false;

		if (str[i] != '.' && str[i] != '-' && str[i] != ':' && isdigit(str[i]))
		{
			sum *= 10;
			sum += str[i] - 48;
		}

		if (str[i] >= 'a' && str[i] <= 'f')
		{
			sum += (str[i] - 87) * weight;
			weight *= 16;
		}
		if (sum > 255)return false;
	}
	if (count_dot != 5)return false;
	return true;
}

bool is_ip_address(char str[])
{
	int count_dot = 0, sum = 0, count_number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '.' && !isdigit(str[i]))return false;
		if (str[i] != '.' && isdigit(str[i]))count_number++;
		if (str[i] == '.')
		{
			count_dot++;
			count_number = 0;
			sum = 0;
		}
		if (count_number > 3)return false;
		if (str[i] != '.' && isdigit(str[i]))
		{
			sum *= 10;
			sum += str[i] - 48;
		}
		if (sum > 255)return false;
	}
	if (count_dot != 3)return false;
	return true;
}