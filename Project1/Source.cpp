#include <iostream>
#include <stdio.h>  //Для puts, putchar


int main(void)
{
    setlocale(LC_ALL, "rus");
    //Код символа «перевод строки»
    int s1 = 10;
    //Код символа «V»
    int s2 = 86;

    puts("Различные способы вывода символов : ");

    //Вывод символов, коды которых записаны в переменные
    putchar(s2);
    putchar(s1);

    //Вывод непосредственно указанных символов
    putchar('V');
    putchar('\n');

    //Вывод символов по их кодам
    putchar(86);
    putchar(10);

    return 0;
}