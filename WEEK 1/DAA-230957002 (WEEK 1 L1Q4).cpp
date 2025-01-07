//          QUESTION 4(LAB 2)

#include <iostream>
using namespace std;

int bruteForceStringMatch(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Match found
        }
    }
    return -1; // No match found
}

int main() {
    string text = "ABABABCABABABCABAB";
    string pattern = "ABABC";

    int result = bruteForceStringMatch(text, pattern);
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}

