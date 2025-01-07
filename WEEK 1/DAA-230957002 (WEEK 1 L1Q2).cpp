//          QUESTION 2(LAB 2)

#include <iostream>
using namespace std;

int gcdConsecutive(int a, int b) {
    int gcd = 1;
    int minVal = (a < b) ? a : b;
    for (int i = 1; i <= minVal; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is: " << gcdConsecutive(a, b) << endl;
    return 0;
}

