#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int to_digit(char c) {
    return c - '0';
}

char to_char(int n) {
    return n + '0';
}

void multiplyBy2(string &s) {
    int carry = 0, d;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        d = 2 * to_digit(s[i]) + carry;
        s[i] = to_char(d % 10);
        carry = d / 10;
    }
    while (carry) {
        s.push_back(to_char(carry % 10));
        carry /= 10;
    }
}

void subtructBy2(string &s) {
    int carry = 0, d, res;
    d = to_digit(s[0]);
    res = d - 2;
    if (res < 0) {
        s[0] = to_char(res + 10);
        carry = 1;
    } else {
        s[0] = to_char(res);
        carry = 0;
    }

    for (int i = 1; i < s.length() && carry; i++) {
        res = to_digit(s[i]) - 1;
        if (res < 0) {
            s[i] = to_char(res + 10);
            carry = 1;
        } else {
            s[i] = to_char(res);
            break;
        }
    }

    reverse(s.begin(), s.end());
    while (s[0] == '0')
        s = s.substr(1, s.length());
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    char s[1000];
    while (scanf("%s", s) == 1) {

        if (strcmp(s, "1") == 0) {
            printf("1\n");
            continue;
        }
        string str(s);
        multiplyBy2(str);
        subtructBy2(str);
        printf("%s\n", str.c_str());
    }
    return 0;
}

