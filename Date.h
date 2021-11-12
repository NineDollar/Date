//
// Created by NewUser on 2021/11/12.
//

#ifndef DATE_DATE_H
#define DATE_DATE_H

#include <iostream>
#include <cstring>

using namespace std;

class Date {
    int year, month, day;

    void itoa(int n, char *s, int fixlen) {
        int i, j, t;
        for (i = 0; n; n = n / 10, i++) {
            s[i] = n % 10 + '0';
        }
        for (; i < fixlen; i++) {
            s[i] = '0';
        }
        s[i] = '\0';
        for (j = 0; j < i / 2; j++) {
            t = s[j];
            s[j] = s[i - 1 - j];
            s[i - 1 - j] = t;
        }
    }

    int atoi(char *s) {
        int n = 0;
        for (; *s; s++) {
            n = n * 10 + *s - '0';
        }
        return n;
    }

public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    void InputDate(istream &in) {
        char y[10], m[10], d[10];
        in.getline(y, 10, '/');  //'/'结束，提取并舍去行尾标志
        in.getline(m, 10, '/');
        in.getline(d, 10, '\n');
        year = atoi(y);
        month = atoi(m);
        day = atoi(d);
    }

    void ShowDate(ostream &out) {
        char DateStr[20];
        char temp[10];
        itoa(year, DateStr, 4);
        itoa(month, temp, 2);
        strcat(DateStr, "/");
        strcat(DateStr, temp);
        itoa(day, temp, 2);
        strcat(DateStr, "/");
        strcat(DateStr, temp);
        out << DateStr;
    }
};

istream &operator>>(istream &in, Date &d) {
    d.InputDate(in);
    return in;
}

ostream &operator<<(ostream &out, Date &d) {
    d.ShowDate(out);
    return out;
}

#endif //DATE_DATE_H
