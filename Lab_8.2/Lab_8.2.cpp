#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void FormatString(char* str) {
    int len = strlen(str);
    int i = 0;

    while (i < len && str[i] != ' ') {
        i++;
    }
    int limit = i;

    char* result = new char[len + 1];
    char* r = result;

    bool in_number = false;
    bool has_dot = false;

    int count = 0;

    i = 0;
    while (i < limit) {
        if (isdigit(str[i])) {
            if (!in_number) {
                in_number = true;
                has_dot = (i > 0 && str[i - 1] == '.');
                count = 0;

                if (!has_dot) {
                    while (str[i] == '0' && i < limit && isdigit(str[i + 1])) {
                        i++;
                    }
                }
            }

            if (!has_dot || (has_dot && count < 2)) {
                *r++ = str[i];
                if (has_dot) count++;
            }
            i++;
        }
        else {
            if (has_dot) {
                while (*(r - 1) == '0' && count > 0) {
                    r--;
                    count--;
                }
                if (*(r - 1) == '.') {
                    r--;
                }
            }

            *r++ = str[i];
            in_number = false;
            has_dot = false;
            i++;
        }
    }

    *r = '\0';

    strcpy(str, result);
    delete[] result;
}

int main() {
    char str[101];
    cout << "Enter string: ";
    cin.getline(str, 100);

    FormatString(str);
    cout << "Formatted string: " << str << endl;

    return 0;
}
