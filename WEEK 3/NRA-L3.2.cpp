#include <iostream>
#include <vector>

int findUnique(const std::vector<int>& arr) {
    int uniqueElement = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        uniqueElement ^= arr[i]; 
    }
    return uniqueElement;
}

int main() {
    int rawArray[] = {4, 3, 6, 3, 4}; 
    std::vector<int> arr(rawArray, rawArray + sizeof(rawArray) / sizeof(rawArray[0]));
    std::cout << "Unique Element: " << findUnique(arr) << std::endl;
    return 0;
}

