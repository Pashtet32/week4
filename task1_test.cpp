#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char * hexad(char string1[], char string2[])
{
    for (int i = 0; i < strlen(string1); i++)
    {
        int number = 0;
        if (isdigit(string1[i]) == true)
        {

            // Нахожу число в строке и запоминаю его
            while (isdigit(string1[i]) == true) {
                int a = (int) string1[i] - '0';
                number = number * 10 + a;
                i++;
            }

            // Добавляю к искомой строке приставку 0х
            strcat(string2, "0x");

            // Перевожу число в 16-ричную систему счисления
            // и загоняю в массив char'ов
            char numberHex[100] = {'\0'};
            int sizeNumberHex = 0;

            while (number>=0)
            {
                int fig = number % 16;
                if (fig > 9)
                {
                    fig += (int) 'A' - 10;
                }
                else
                {
                    fig += (int) '0';
                }
                numberHex[sizeNumberHex] = (char) fig;
                sizeNumberHex++;
                number = number / 16;
                if (number == 0)
                    number--;
            }

            // Число получилось задом наперед, провожу инверсию массива числа
                for (int j = 0; j < sizeNumberHex / 2; j++)
                {
                    char b = numberHex[j];
                    numberHex[j] = numberHex[sizeNumberHex - 1 - j];
                    numberHex[sizeNumberHex - 1 - j] = b;
                }

            // После приставки 0х добавляю само число строкой
            strcat(string2, numberHex);
            i--;
        }

        else
        {
            // Если элемент строки является не числом,
            // то просто добавляю в искомую строку элемент
            char element[2] = {string1[i], '\0'};
            strcat(string2, element);
        }

    }
    return string2;
}

void test (char ProgramResult[], char TrueResult[])
{
    if (strcmp(ProgramResult, TrueResult) == 0)
    {
        cout << "CORRECT" << endl;
    }
    else
        cout <<"INCORRECT"<<endl;
}

int main ()
{
    char  str2[100] = {'\0'};
    char *str1 = "";
    hexad(str1,str2);
    test (str2, "");

    str1 ="1";
    hexad(str1,str2);
    test (str2, "0x1");

    str1 = "alskdsdbfgfiuuheighsddrviiurt";
    char  str3[100] = {'\0'};
    hexad(str1,str3);
    test (str3, str1);

    str1 = "00000000000000000000000000000016";
    char  str4[100] = {'\0'};
    hexad(str1,str4);
    test (str4, "0x10");

    str1 = "k19k18v17d16f15o14b13o12i11a10p9p8d7f6o5d4o3o2v1soi";
    char  str5[100] = {'\0'};
    hexad(str1,str5);
    test (str5, "k0x13k0x12v0x11d0x10f0xFo0xEb0xDo0xCi0xBa0xAp0x9p0x8d0x7f0x6o0x5d0x4o0x3o0x2v0x1soi");

    str1 = "2345588";
    char  str6[100] = {'\0'};
    hexad(str1,str6);
    test (str6, "0x23CA74");


    return 0;
}
