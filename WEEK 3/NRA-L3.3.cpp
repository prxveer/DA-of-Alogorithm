#include <iostream>
#include <vector>

std::vector<std::vector<int> > multiplyMatrices(const std::vector<std::vector<int> >& A, 
                                                const std::vector<std::vector<int> >& B, int n) {
    std::vector<std::vector<int> > result(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rawA[2][2] = {{2, 2}, {3, 7}};
    int rawB[2][2] = {{3, 6}, {6, 8}};
    int n = 2;

    std::vector<std::vector<int> > A, B;
    for (int i = 0; i < n; ++i) {
        A.push_back(std::vector<int>(rawA[i], rawA[i] + n)); 
        B.push_back(std::vector<int>(rawB[i], rawB[i] + n));
    }

    std::vector<std::vector<int> > result = multiplyMatrices(A, B, n);
    std::cout << "Product Matrix:" << std::endl;
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

