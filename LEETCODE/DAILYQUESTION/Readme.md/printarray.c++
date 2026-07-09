#include <iostream>
#include <vector>

// Function to print the elements of a std::vector<int>
void printArray(const std::vector<int>& arr) {
    std::cout << "Array elements: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    printArray(myVector);

    std::vector<int> emptyVector;
    printArray(emptyVector);

    std::vector<int> singleElementVector = {100};
    printArray(singleElementVector);

    return 0;
}