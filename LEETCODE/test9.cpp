#include <bits/stdc++.h>
using namespace std;

// Utility functions
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

vector<int> fibonacci(int n) {
    vector<int> f(n);
    if (n > 0) f[0] = 0;
    if (n > 1) f[1] = 1;
    for (int i = 2; i < n; i++) f[i] = f[i-1] + f[i-2];
    return f;
}

// String utilities
bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

string reverseString(const string &s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r;
}

map<char,int> frequencyCount(const string &s) {
    map<char,int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// Pattern printing
void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) cout << " ";
        for (int j = 1; j <= (2*i-1); j++) cout << "*";
        cout << endl;
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = n; j > i; j--) cout << " ";
        for (int j = 1; j <= (2*i-1); j++) cout << "*";
        cout << endl;
    }
}

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

void printCheckerboard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i+j)%2==0) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
}

// Matrix operations
vector<vector<int>> addMatrix(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    vector<vector<int>> C(n, vector<int>(m,0));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for (int k=0;k<p;k++)
                C[i][j] += A[i][k]*B[k][j];
    return C;
}

// File I/O
void saveToFile(const string &filename, const string &data) {
    ofstream fout(filename);
    fout << data;
    fout.close();
}

string loadFromFile(const string &filename) {
    ifstream fin(filename);
    stringstream buffer;
    buffer << fin.rdbuf();
    return buffer.str();
}

// Classes
class Student {
public:
    string name;
    int age;
    double grade;
    Student(string n, int a, double g): name(n), age(a), grade(g) {}
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

// Menu system
void menu() {
    cout << "\n=== Multi Feature C++ App ===\n";
    cout << "1. Factorial\n";
    cout << "2. Prime Check\n";
    cout << "3. Fibonacci\n";
    cout << "4. Palindrome Check\n";
    cout << "5. Reverse String\n";
    cout << "6. Frequency Count\n";
    cout << "7. Diamond Pattern\n";
    cout << "8. Pyramid Pattern\n";
    cout << "9. Checkerboard Pattern\n";
    cout << "10. Matrix Addition\n";
    cout << "11. Matrix Multiplication\n";
    cout << "12. Save to File\n";
    cout << "13. Load from File\n";
    cout << "14. Student Record\n";
    cout << "0. Exit\n";
}


int main() {
    int choice;
    do {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice==1) {
            int n; cout << "Enter n: "; cin >> n;
            cout << "Factorial: " << factorial(n) << endl;
        } else if (choice==2) {
            int n; cout << "Enter n: "; cin >> n;
            cout << (isPrime(n) ? "Prime" : "Not Prime") << endl;
        } else if (choice==3) {
            int n; cout << "Enter n: "; cin >> n;
            auto f = fibonacci(n);
            for (int x : f) cout << x << " ";
            cout << endl;
        } else if (choice==4) {
            string s; cout << "Enter string: "; cin >> s;
            cout << (isPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;
        } else if (choice==5) {
            string s; cout << "Enter string: "; cin >> s;
            cout << "Reversed: " << reverseString(s) << endl;
        } else if (choice==6) {
            string s; cout << "Enter string: "; cin >> s;
            auto freq = frequencyCount(s);
            for (auto &p : freq) cout << p.first << ": " << p.second << endl;
        } else if (choice==7) {
            int n; cout << "Enter size: "; cin >> n;
            printDiamond(n);
        } else if (choice==8) {
            int n; cout << "Enter size: "; cin >> n;
            printPyramid(n);
        } else if (choice==9) {
            int n; cout << "Enter size: "; cin >> n;
            printCheckerboard(n);
        } else if (choice==10) {
            int n,m; cout << "Enter rows and cols: "; cin >> n >> m;
            vector<vector<int>> A(n, vector<int>(m)), B(n, vector<int>(m));
            cout << "Enter matrix A:\n";
            for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> A[i][j];
            cout << "Enter matrix B:\n";
            for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> B[i][j];
            auto C = addMatrix(A,B);
            cout << "Result:\n";
            for (auto &row : C) { for (int x : row) cout << x << " "; cout << endl; }
        } else if (choice==11) {
            int n,m,p; cout << "Enter rows of A, cols of A, cols of B: "; cin >> n >> m >> p;
            vector<vector<int>> A(n, vector<int>(m)), B(m, vector<int>(p));
            cout << "Enter matrix A:\n";
            for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> A[i][j];
            cout << "Enter matrix B:\n";
            for (int i=0;i<m;i++) for (int j=0;j<p;j++) cin >> B[i][j];
            auto C = multiplyMatrix(A,B);
            cout << "Result:\n";
            for (auto &row : C) { for (int x : row) cout << x << " "; cout << endl; }
        } else if (choice==12) {
            string filename,data;
            cout << "Filename: "; cin >> filename;
            cout << "Data: "; cin.ignore(); getline(cin,data);
            saveToFile(filename,data);
            cout << "Saved.\n";
        } else if (choice==13) {
            string filename;
            cout << "Filename: "; cin >> filename;
            cout << "Loaded:\n" << loadFromFile(filename) << endl;
        } else if (choice==14) {
            string name; int age; double grade;
            cout << "Enter name age grade: ";
            cin >> name >> age >> grade;
            Student s(name, age, grade);
            s.display();
        } else if (choice==0) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
