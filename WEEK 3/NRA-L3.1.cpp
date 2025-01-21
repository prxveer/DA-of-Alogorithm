#include <iostream>
#include <vector>
#include <climits>

int findMax(const std::vector<int>& arr) 
{
    int maxElement = INT_MIN; 
    for (size_t i = 0; i < arr.size(); ++i) 
	{
        if (arr[i] > maxElement) 
		{
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() 
{
    int rawArray[] = {3, 1, 4, 1, 5, 9, 2}; 
    std::vector<int> arr(rawArray, rawArray + sizeof(rawArray) / sizeof(rawArray[0]));
    std::cout << "Maximum Element: " << findMax(arr) << std::endl;
    return 0;
}

