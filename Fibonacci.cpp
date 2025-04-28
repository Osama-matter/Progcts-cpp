#include <iostream>
#include <vector>
using namespace std;

int GetNumber() {
    int number = 0;
    do {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number <= 0);
    return number;
}

void GenerateFibonacciNumbers(vector<int>& FibonacciNumbers, int number) {
    int val1 = 0, val2 = 1; // Correct initialization
    int sum = 1;
    for (int i = 0; i < number; i++) {
        
        
        FibonacciNumbers.push_back(sum);
        sum = val1 + val2;
        val1 = val2;
        val2 = sum;
    
    }
}

void PrintResults(const vector<int>& FibonacciNumbers) {
    for (int num : FibonacciNumbers) {
        cout << num << "    ";
    }
    cout << endl;
}

int main() {
    int number = GetNumber();
    vector<int> FibonacciNumbers;

    GenerateFibonacciNumbers(FibonacciNumbers, number);
    cout << "FIlbonacci number is : ";
    PrintResults(FibonacciNumbers);

    return 0;
}
