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

int main ()
{
    char str1[100], str2[100] = {'\0'};
    cin >> str1;
    hexad(str1,str2);
    cout << str2 << endl << str1 << endl;
    
    return 0;
}