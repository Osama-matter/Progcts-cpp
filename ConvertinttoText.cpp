#include <iostream>
using namespace std;

string ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
string teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

string convertNumber(int number)
{
    string result = "";

    if (number == 0) {
        result += "Zero";
    }
    else if (number < 10) {
        result += ones[number];
    }
    else if (number >= 10 && number < 20) {
        result += teens[number - 10];
    }
    else if (number >= 20 && number < 100) {
        result += tens[number / 10];
        if (number % 10 != 0)
            result += " " + convertNumber(number % 10);
    }
    else if (number >= 100 && number < 1000) {
        result += ones[number / 100] + " Hundred";
        if (number % 100 != 0)
            result += " " + convertNumber(number % 100);
    }
    else if (number >= 1000 && number < 10000) {
        result += ones[number / 1000] + " Thousand";
        if (number % 1000 != 0)
            result += " " + convertNumber(number % 1000);
    }
    else if (number >= 10000 && number < 20000) {
        result += teens[(number / 1000) - 10] + " Thousand";
        if (number % 1000 != 0)
            result += " " + convertNumber(number % 1000);
    }
    else if (number >= 20000 && number < 100000) {
        result += tens[(number / 10000)];
        if ((number / 1000) % 10 != 0)
            result += " " + ones[(number / 1000) % 10];
        result += " Thousand";
        if (number % 1000 != 0)
            result += " " + convertNumber(number % 1000);
    }
    else if (number >= 100000 && number < 1000000) {
        result += ones[number / 100000] + " Hundred";
        int remainder = number % 100000;
        if (remainder >= 1000) {
            result += " " + convertNumber(remainder / 1000) + " Thousand";
            if (remainder % 1000 != 0)
                result += " " + convertNumber(remainder % 1000);
        }
        else if (remainder != 0) {
            result += " " + convertNumber(remainder);
        }
    }

    return result;
}

int main()
{
    int number;
    cout << "Enter a number (0 to 999999): ";
    cin >> number;

    if (number < 0 || number > 999999) {
        cout << "Please enter a number between 0 and 999999." << endl;
    }
    else {
        cout << convertNumber(number) << endl;
    }

    return 0;
}
