#include <iostream>
#include <stdio.h>  //��� puts, putchar


int main(void)
{
    setlocale(LC_ALL, "rus");
    //��� ������� �������� ������
    int s1 = 10;
    //��� ������� �V�
    int s2 = 86;

    puts("��������� ������� ������ �������� : ");

    //����� ��������, ���� ������� �������� � ����������
    putchar(s2);
    putchar(s1);

    //����� ��������������� ��������� ��������
    putchar('V');
    putchar('\n');

    //����� �������� �� �� �����
    putchar(86);
    putchar(10);

    return 0;
}