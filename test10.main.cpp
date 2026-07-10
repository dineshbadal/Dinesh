#include <iostream>

int main() {
    int n = 20; // Number of Fibonacci elements to print
    int a = 0;
    int b = 1;
    int nextTerm;

    std::cout << "Fibonacci Series up to " << n << " elements:" << std::endl;

    for (int i = 1; i <= n; ++i) {
        std::cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    std::cout << std::endl;

    return 0;
}