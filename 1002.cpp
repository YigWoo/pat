#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string nums[10] = {"ling","yi", "er", "san", "si", "wu",
                   "liu", "qi", "ba", "jiu"};
    int c;
    int total = 0;
    while ((c = getchar()) != EOF) {
        if ( c != '\n') {
            int  t = c - '0';
            total += t;
        }
    }
    
    int digit = 0;
    if (total == 0) {
        digit = 1;
    } else {
        int tmp = total;
        while (tmp != 0) {
            tmp /= 10;
            digit++;
        }
    }
    
    string out;
    for (int i = 0; i < digit; i++) {
        out = nums[total%10] + out;
        if (i != digit -1) out = " " + out;
        total /= 10;
    }
    cout << out;
}
