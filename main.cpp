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

void assert(char ch[], float res)
{
    if (process(ch) == res)
        cout << "ok" << endl;
    else
        cout << "very bad" << endl;
}

int main()
{
//    char st[256];
//    cin.getline(st, 256);
//    cout << process(st);
    assert ("1+1", 2);
    assert ("1+1-10 +  1008", 1000);
    assert ("1+1 - - 1", 1);
    assert ("11 - 11 + 22", 22);
    assert ("1-11", -10);
    assert ("1 - 2 + 3 - 4 + 5 - 6 + 7", 4);
    assert ("1 - 1 + 1  - 1 + 1 -1", 0);
    assert ("134", 134);
    assert ("111-222", -111);
    assert ("1-1", 0);
    return 0;
}
