#include <iostream>

int countBinaryDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 2;
        ++count;
    }
    return count;
}

int main() {
    int n = 37;
    std::cout << "Number of Binary Digits: " << countBinaryDigits(n) << std::endl;
    return 0;
}

