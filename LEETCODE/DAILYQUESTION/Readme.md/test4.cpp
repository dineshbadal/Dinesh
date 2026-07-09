#include <iostream>
#include <vector>
using namespace std ;
// Function to print the elements of a vector<int>
void printArray(const vector<int>& arr) {
    cout << "Array elements: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};
    printArray(myVector);

    vector<int> emptyVector;
    printArray(emptyVector);

    vector<int> singleElementVector = {100};
    printArray(singleElementVector);

    return 0;
}