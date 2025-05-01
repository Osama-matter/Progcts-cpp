#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Datefromcastomar {
    string AccountNumber;
    string AccountPassword;
    string Name;
    string Number;
    int AccountBalance;
    bool found = false; 
};

string GetClientNumber() {
    string ClintNumber;
    cout << "Enter Account Number of the client to delete: ";
    cin >> ClintNumber;
    return ClintNumber;
}

string ReadFile(string filename) {
    fstream Myfile(filename, ios::in);
    string content, line;
    if (Myfile.is_open()) {
        while (getline(Myfile, line)) {
            content += line + "#//";
        }
        Myfile.close();
    }
    return content;
}

void splitFunction(string content, vector<string>& result, string delimiter) {
    size_t pos = 0;
    while ((pos = content.find(delimiter)) != string::npos) {
        string token = content.substr(0, pos);
        if (!token.empty()) result.push_back(token);
        content.erase(0, pos + delimiter.length());
    }
    if (!content.empty()) result.push_back(content);
}

Datefromcastomar extractClient(const vector<string>& text, int startIndex) {
    Datefromcastomar p;
    if (startIndex + 4 < text.size()) {
        p.AccountNumber = text[startIndex];
        p.AccountPassword = text[startIndex + 1];
        p.Name = text[startIndex + 2];
        p.Number = text[startIndex + 3];
        p.AccountBalance = stoi(text[startIndex + 4]);
        p.found = true; 
    }
    return p;
}

void printClient(const Datefromcastomar& p) {
    cout << " ---------------------------------------------------------------------------------------------\n";
    cout << "| " << setw(16) << left << "Account Number"
        << "| " << setw(16) << left << "Pin Code"
        << "| " << setw(20) << left << "Client Name"
        << "| " << setw(15) << left << "Phone"
        << "| " << setw(10) << left << "Balance"
        << "|\n";
    cout << " ---------------------------------------------------------------------------------------------\n";

    cout << "| " << setw(16) << left << p.AccountNumber
        << "| " << setw(16) << left << p.AccountPassword
        << "| " << setw(20) << left << p.Name
        << "| " << setw(15) << left << p.Number
        << "| " << setw(10) << left << p.AccountBalance
        << "|\n";
    cout << " ---------------------------------------------------------------------------------------------\n";
}

void SaveClientsToFile(const vector<Datefromcastomar>& clients, string filename) {
    ofstream MyFile(filename, ios::out);
    if (MyFile.is_open()) {
        for (const auto& c : clients) {
            MyFile << c.AccountNumber << "#//"
                << c.AccountPassword << "#//"
                << c.Name << "#//"
                << c.Number << "#//"
                << c.AccountBalance << "#//" << endl;
        }
        MyFile.close();
    }
}
Datefromcastomar FindClientByAccountNumber(const string& ClintNumber, const vector<Datefromcastomar>& clients) {
    for (const auto& c : clients) {
        if (c.AccountNumber == ClintNumber) {
            Datefromcastomar result = c;
            result.found = true;
            return result;
        }
    }
    return Datefromcastomar{}; // Found = false by default
}

bool ifuserwonttoDelet()
{
    bool Deleat = false;
    char chose = ' ';
    cout << "Do you wont to Delete User (y /n) ?  \n"; 
    cin >> chose;
    if (chose == 'y' || 'Y')
        return true;
    else
        return false;
}
void Start() {
    char answer;
    do {
        system("cls");

        string ClintNumber = GetClientNumber();
        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (size_t i = 0; i + 4 < text.size(); i += 5) {
            clients.push_back(extractClient(text, i));
        }

        bool found = false;
        vector<Datefromcastomar> filteredClients;

        Datefromcastomar resulats;
        resulats = FindClientByAccountNumber(ClintNumber, clients); 

        if (resulats.found ) {
            for (const auto& c : clients) {
                if (c.AccountNumber != ClintNumber) {
                    filteredClients.push_back(c);
                }
            }
            printClient(resulats);
           
            if (ifuserwonttoDelet())
            {
                SaveClientsToFile(filteredClients, "emplyeefile.txt");
            }

           

            cout << "\nClient deleted successfully.\n";
        }

        else {
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to delete another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}

int main() {
    Start();
}
