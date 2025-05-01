#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h> 

using namespace std;

struct Datefromcastomar {
    string AccountNumber;
    string AccountPassword;
    string Name;
    string Number;
    int AccountBalance;
    bool found = false; 
};

string GetClientNumber(string massager) {
    string ClintNumber;
    cout << massager;
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
            break;
        }
    }
    return Datefromcastomar{}; // Found = false by default
}

bool ifuserwonttoDelet()
{
    bool Deleat = false;
    char chose = ' ';
    cout << "Do you wont to Edit User (y /n) ?  \n"; 
    cin >> chose;
    return (chose == 'y' ||chose== 'Y');
}
Datefromcastomar GetDataToEditIt(Datefromcastomar& p1)
{
 
    cout << "\nEnter Account Possaword  ? ";
    getline(cin>> ws, p1.AccountPassword);
    cout << "\nEnter Name ? ";
    getline(cin, p1.Name);
    cout << "\nEnter Your Number ? ";
    getline(cin, p1.Number);
    cout << "\nEnter Account Balance ? ";
    cin >> p1.AccountBalance;
    return p1;
}
Datefromcastomar GetData(Datefromcastomar& p1)
{
    cout << "\nEnter Account Number ? ";
    getline(cin >> ws, p1.AccountNumber);
    cout << "\nEnter Account Possaword  ? ";
    getline(cin >> ws, p1.AccountPassword);
    cout << "\nEnter Name ? ";
    getline(cin, p1.Name);
    cout << "\nEnter Your Number ? ";
    getline(cin, p1.Number);
    cout << "\nEnter Account Balance ? ";
    cin >> p1.AccountBalance;
    return p1;
}
string MakeDatainString(Datefromcastomar p1, string S2, string dime)
{
    S2 += p1.AccountNumber + dime;
    S2 += p1.AccountPassword + dime;
    S2 += p1.Name + dime;
    S2 += p1.Number + dime;
    S2 += to_string(p1.AccountBalance);
    return S2;
}
void Printresulatsinfile(Datefromcastomar p1, string  dime, string S2)
{
    fstream myfile;
    myfile.open("emplyeefile.txt", ios::out | ios::app);
    if (myfile.is_open())
    {
        S2 = MakeDatainString(p1, S2, "#//");
        myfile << S2 << endl;
    }
}
void StartShowClientList()
{
    system("cls");
   
    //string ClintNumber = GetClientNumber();
    string fileContent = ReadFile("emplyeefile.txt");
    vector<string> text; 
    splitFunction(fileContent, text, "#//");
    Datefromcastomar p;
    for (int i = 0;i < text.size(); i+=5)
    {
        p=extractClient(text, i);
        printClient(p);
    } 
}
void StartEditFanction() {
    char answer;
    do {
        system("cls");
        string S2; 
        string ClintNumber = GetClientNumber("Enter User Number Do you Wont To Edit Info ? ");
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
                GetDataToEditIt(resulats);
                printClient(resulats);
                filteredClients.push_back(resulats);
                SaveClientsToFile(filteredClients, "emplyeefile.txt");
            }

           

            cout << "\nClient Edited successfully.\n";
        }

        else {
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to Edit another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}

void StarttoDeleteClientFile() {
    char answer;
    do {
        system("cls");

        string ClintNumber = GetClientNumber("Enter User Number Do you Wont To Delete Info ? ");
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

        if (resulats.found) {
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


void StarttoAddClientinFile()
{
    char again;
    do {
        system("cls");

        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (int i = 0; i + 4 < text.size(); i += 5)
        {
            clients.push_back(extractClient(text, i));
        }

        Datefromcastomar p1;
        p1 = GetData(p1);

        bool nameExists = false;
        for (const auto& c : clients)
        {
            if (c.Name == p1.Name)
            {
                nameExists = true;
                break;
            }
        }

        if (nameExists)
        {
            cout << "\n[!] Client with the same name already exists. Cannot add.\n";
        }
        else
        {
            clients.push_back(p1);
            SaveClientsToFile(clients, "emplyeefile.txt");
            cout << "\n[+] Client added successfully.\n";
        }

        cout << "\nDo you want to add another client? (y/n): ";
        cin >> again;

    } while (tolower(again) == 'y');

}


void StartToFindClient() {
    char answer;
    do {
        system("cls");
        string ClintNumber = GetClientNumber("Enter User Number Do you Wont To Find Info ? ");
        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (size_t i = 0; i + 4 < text.size(); i += 5) {
            clients.push_back(extractClient(text, i));
        }

        Datefromcastomar result = FindClientByAccountNumber(ClintNumber, clients);

        if (result.found) {
            printClient(result);
        }
        else {
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to search for another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}
void StartSystem()
{
    do
    {
        system("cls");
        short Chose = 0;
        char CHar = ' ';
        cout << "==================================================================================================\n\n";
        cout << "\t\t Client Management System\t\t              \n\n";
        cout << "==================================================================================================\n\n";
        cout << "[1] Show Client List \n";
        cout << "[2] Add New Client \n";
        cout << "[3] Delete Clients \n";
        cout << "[4] Update Client Info \n";
        cout << "[5] Find Client \n";
        cout << "[6] Exit \n";
        cout << "=======================================================================================================\n\n";
        cout << "Enter your Chose ? ";
        cin >> Chose;
        switch (Chose)
        {
        case (1):
            StartShowClientList();
            cout << "Press Any Key To Return ...";
            _getch();
            system("cls");
            break;
        case (2):
            StarttoAddClientinFile();
            break;
        case (3):
            StarttoDeleteClientFile();
            break;
        case (4):
            StartEditFanction();
            break;
        case (5):
            StartToFindClient();
            break;
        case (6):
            system("cls");
            cout << "===========================================================================================\n\n";
            cout << "\t\tGood Lack \t\t \n\n";
            cout << "===========================================================================================\n\n";
            break;
        default:
            cout << "Un Valied Chose . \n"; 
            break;
        }
        cout << "Press Any Key To Return ...";
        _getch();;
    } while (_getch());
}
int main()
{
    StartSystem();
}
