#include <iostream>
#include <algorithm>
using namespace std;

int calculateCost(int costMatrix[][4], int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

int assignmentProblemBruteForce(int costMatrix[][4], int n) {
    int assignment[n];
    for (int i = 0; i < n; i++) {
        assignment[i] = i;
    }

    int minCost = 1000000;
    
    do {
        int currentCost = calculateCost(costMatrix, assignment, n);
        minCost = min(minCost, currentCost);
    } while (next_permutation(assignment, assignment + n));

    return minCost;
}

int main() {
    int costMatrix[4][4] = {
        {10, 2, 8, 12},
        {4, 5, 7, 9},
        {6, 3, 9, 11},
        {12, 6, 4, 10}
    };

    int n = 4;
    cout << "The minimum cost of assignment is: " << assignmentProblemBruteForce(costMatrix, n) << endl;

    return 0;
}

