#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

float process (char st[])
{
    char st2[256];
    strcpy(st2, st);
    char *num = strtok(st2, "+-");
    float res;
    res = atof(num);
    for (int i  = 0; i < strlen(st); i++)
    {
        if (st[i] == '+')
        {
            num = strtok(NULL, "+-");
            res += atof(num);
        }
        if (st[i] == '-')
        {
            num = strtok(NULL, "+-");
            res -= atof(num);
        }
    }

    return res;
}

int main()
{
    char st[256];
    cin.getline(st, 256);
    cout << process(st);
    return 0;
}
