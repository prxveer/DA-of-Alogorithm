#include <iostream>
using namespace std;

int countBinaryDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countBinaryDigits(n / 2);
}

int main() {
    int n = 37;
    cout << "Number of Binary Digits in " << n << " is: " << countBinaryDigits(n) << endl;
    return 0;
}

