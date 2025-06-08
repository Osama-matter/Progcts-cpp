#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h> 


using namespace std;

struct Users {
    string AccountName;
    string AccountPassword;
    int Permation;
    bool found = false;
};

string GetClientNumberUsers(string massager) {
    string Users;
    cout << massager;
    cin >> Users;
    return Users;
}

string ReadUsersFileUsers(string filename) {
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

void splitFunctionUsers(string content, vector<string>& User, string delimiter) {
    size_t pos = 0;
    while ((pos = content.find(delimiter)) != string::npos) {
        string token = content.substr(0, pos);
        if (!token.empty()) User.push_back(token);
        content.erase(0, pos + delimiter.length());
    }
    if (!content.empty()) User.push_back(content);
}

Users extractClientUsers(const vector<string>& User, int startIndex) {
    Users p;
    if (startIndex + 2 < User.size()) {
        p.AccountName = User[startIndex];
        p.AccountPassword = User[startIndex + 1];
        p.Permation = stoi(User[startIndex + 2]);
        p.found = true;
    }
    return p;
}

void printUsers(const Users& p) {
    cout << " ---------------------------------------------------------------------------------------------\n";
    cout << "| " << setw(16) << left << "Account Name"
        << "| " << setw(16) << left << "Password"
        << "| " << setw(16) << left << "Permation"

        << "|\n";
    cout << " ---------------------------------------------------------------------------------------------\n";

    cout << "| " << setw(16) << left << p.AccountName
        << "| " << setw(16) << left << p.AccountPassword
        << "| " << setw(16) << left << p.Permation
        << "|\n";
    cout << " ---------------------------------------------------------------------------------------------\n";
}

void SaveUsersToFile(const vector<Users>& clients, string filename) {
    ofstream MyFile(filename, ios::out);
    if (MyFile.is_open()) {
        for (const auto& c : clients) {
            MyFile << c.AccountName << "#//"
                << c.AccountPassword << "#//"
                << c.Permation << "#//";
        }
        MyFile.close();
    }
}

Users FindUsersByAccountNumber(const string& ClintNumber, const vector<Users>& clients) {
    for (const auto& c : clients) {
        if (c.AccountName == ClintNumber) {
            Users result = c;
            result.found = true;
            return result;
        }
    }
    return Users{}; // Found = false by default
}
Users FindUsersByAccountNumberTODelete(const string& ClintNumber, const vector<Users>& clients) {
    for (const auto& c : clients) {
        if (c.AccountName == ClintNumber) 
        {
            if (c.AccountName == "admin")
            {
                cout << "\n\t\tCant Delete Admin .\n";
                Users result = c;
                result.found = false;
                return result;
            }
            else
            {
                Users result = c;
                result.found = true;
                return result;
            }

        }
    }
    return Users{}; // Found = false by default
}
Users FindUsersByAccountNumberAndPassword(const string& UserName , const string& Password , const vector<Users>& clients) {
    for (const auto& c : clients) {
        if (c.AccountName ==UserName && c.AccountPassword == Password ) {
            Users result = c;
            result.found = true;
            return result;
        }
    }
    return Users{}; // Found = false by default
}

bool ifuserwonttoDelet() {
    char chose = ' ';
    cout << "Do you wont to Edit User (y /n) ?  \n";
    cin >> chose;
    return (chose == 'y' || chose == 'Y');
}

Users GetDataToEditItUsers(Users& p1) {
    cout << "\nEnter Account Name ? ";
    getline(cin >> ws, p1.AccountName);
    cout << "\nEnter Password  ? ";
    getline(cin, p1.AccountPassword);
    return p1;
}

Users GetDataUsers(Users& p1) {
    cout << "\nEnter Account Number ? ";
    getline(cin >> ws, p1.AccountName);
    cout << "\nEnter Account Possaword  ? ";
    getline(cin >> ws, p1.AccountPassword);
    cout << "\nEnter Permission (number) ? ";
    cin >> p1.Permation;
    return p1;
}

string MakeDatainStringUsers(Users p1, string S2, string dime) {
    S2 += p1.AccountName + dime;
    S2 += p1.AccountPassword + dime;
    S2 += to_string(p1.Permation) + dime;
    return S2;
}

void PrintresulatsinfileUsers(Users p1, string  dime, string S2) {
    fstream myfile;
    myfile.open("Users", ios::out | ios::app);
    if (myfile.is_open()) {
        S2 = MakeDatainStringUsers(p1, S2, "#//");
        myfile << S2 << endl;
    }
}

void StartShowUsers() {
    system("cls");
    string fileContent = ReadUsersFileUsers("Users.txt");
    vector<string> text;
    splitFunctionUsers(fileContent, text, "#//");
    Users p;
    for (int i = 0; i + 2 < text.size(); i += 3) {
        p = extractClientUsers(text, i);
        printUsers(p);
    }
}

void StartEditFanctionUsers() {
    char answer;
    do {
        system("cls");
        string S2;
        string ClintNumber = GetClientNumberUsers("Enter User Number Do you Wont To Edit Info ? ");
        string fileContent = ReadUsersFileUsers("Users.txt");
        vector<string> text;
        splitFunctionUsers(fileContent, text, "#//");

        vector<Users> clients;
        for (size_t i = 0; i + 2 < text.size(); i += 3) {
            clients.push_back(extractClientUsers(text, i));
        }

        vector<Users> filteredClients;
        Users resulats = FindUsersByAccountNumber(ClintNumber, clients);

        if (resulats.found) {
            for (const auto& c : clients) {
                if (c.AccountName != ClintNumber) {
                    filteredClients.push_back(c);
                }
            }
            printUsers(resulats);

            if (ifuserwonttoDelet()) {
                GetDataToEditItUsers(resulats);
                printUsers(resulats);
                filteredClients.push_back(resulats);
                SaveUsersToFile(filteredClients, "Users.txt");
                cout << "\nClient Edited successfully.\n";
            }
        }
        else {
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to Edit another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}

void StarttoDeleteClientFileUsers() {
    char answer;
    do {
        system("cls");
        string ClintUserName = GetClientNumberUsers("Enter User Name Do you Wont To Delete Info ? ");
        string fileContent = ReadUsersFileUsers("Users.txt");
        vector<string> text;
        splitFunctionUsers(fileContent, text, "#//");

        vector<Users> clients;
        for (size_t i = 0; i + 2 < text.size(); i += 3) {
            clients.push_back(extractClientUsers(text, i));
        }

        vector<Users> filteredClients;
        Users resulats = FindUsersByAccountNumberTODelete(ClintUserName, clients);

        if (resulats.found) {
            for (const auto& c : clients) {
                if (c.AccountName != ClintUserName) {
                    filteredClients.push_back(c);
                }
            }
            printUsers(resulats);

            if (ifuserwonttoDelet()) {
                SaveUsersToFile(filteredClients, "Users.txt");
                cout << "\nClient deleted successfully.\n";
            }
        }
        else 
        {
            if (ClintUserName !="admin")
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to delete another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}

void StarttoAddClientinFileUsers() {
    char again;
    do {
        system("cls");
        string fileContent = ReadUsersFileUsers("Users.txt");
        vector<string> text;
        splitFunctionUsers(fileContent, text, "#//");

        vector<Users> clients;
        for (int i = 0; i + 2 < text.size(); i += 3) {
            clients.push_back(extractClientUsers(text, i));
        }

        Users p1;
        p1 = GetDataUsers(p1);

        bool nameExists = false;
        for (const auto& c : clients) {
            if (c.AccountName == p1.AccountName) {
                nameExists = true;
                break;
            }
        }

        if (nameExists) {
            cout << "\n[!] Client with the same name already exists. Cannot add.\n";
        }
        else {
            clients.push_back(p1);
            SaveUsersToFile(clients, "Users.txt");
            cout << "\n[+] Client added successfully.\n";
        }

        cout << "\nDo you want to add another client? (y/n): ";
        cin >> again;
    } while (tolower(again) == 'y');
}

void StartToFindClientUsers() {
    char answer;
    do {
        system("cls");
        string ClintNumber = GetClientNumberUsers("Enter User Number Do you Wont To Find Info ? ");
        string fileContent = ReadUsersFileUsers("Users.txt");
        vector<string> text;
        splitFunctionUsers(fileContent, text, "#//");

        vector<Users> clients;
        for (size_t i = 0; i + 2 < text.size(); i += 3) {
            clients.push_back(extractClientUsers(text, i));
        }

        Users result = FindUsersByAccountNumber(ClintNumber, clients);

        if (result.found) {
            printUsers(result);
        }
        else {
            cout << "\nClient not found.\n";
        }

        cout << "Do you want to search for another client? (y/n): ";
        cin >> answer;
    } while (tolower(answer) == 'y');
}


void StartSystemUsers() {
    do {
        system("cls");
        short Chose = 0;
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

        switch (Chose) {
        case 1:
            StartShowUsers();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case 2:
            StarttoAddClientinFileUsers();
            break;
        case 3:
            StarttoDeleteClientFileUsers();
            break;
        case 4:
            StartEditFanctionUsers();
            break;
        case 5:
            StartToFindClientUsers();
            break;
        case 6:
            cout << "\n\nPress Any Key To Return ...";
            _getch();
            return;
        default:
            cout << "Un Valied Chose . \n";
            break;
        }
        cout << "\n\nPress Any Key To Return ...";
        _getch();
    } while (true);
}


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
float GetDepositAmount(string Massage)
{
    float Deposit = 0;
    char chose = ' ';
    cout << Massage;
    cin >> Deposit;
    cout << " You are Sure  to Make Deposit (y / n) \n";
    cin >> chose;
    if (chose == 'y' || chose == 'Y')
    {
        cout << "Opreration Suceccful \n";
        return Deposit;


    }
    else
        return 0;
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

Datefromcastomar GetDataToEditIt(Datefromcastomar& p1)
{

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
    cout << "==================================================================================================\n\n";
    cout << "\t\t Show Client Data Mode\t\t              \n\n";
    cout << "==================================================================================================\n\n";
    //string ClintNumber = GetClientNumber();
    string fileContent = ReadFile("emplyeefile.txt");
    vector<string> text;
    splitFunction(fileContent, text, "#//");
    Datefromcastomar p;
    for (int i = 0;i < text.size(); i += 5)
    {
        p = extractClient(text, i);
        printClient(p);
    }
}
void StartEditFanction() {
    char answer;
    do {
        system("cls");
        cout << "==================================================================================================\n\n";
        cout << "\t\t Edit Mode\t\t              \n\n";
        cout << "==================================================================================================\n\n";

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

        if (resulats.found) {
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
        cout << "==================================================================================================\n\n";
        cout << "\t\t Delete Mode \t\t              \n\n";
        cout << "==================================================================================================\n\n";


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
        cout << "==================================================================================================\n\n";
        cout << "\t\t Add Mode \t\t              \n\n";
        cout << "==================================================================================================\n\n";


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
        cout << "==================================================================================================\n\n";
        cout << "\t\t FInd Mode \t\t              \n\n";
        cout << "==================================================================================================\n\n";

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

void StartToMakeDepositClient() {
    char answer;
    do {
        system("cls");
        cout << "==================================================================================================\n\n";
        cout << "\t\t Deposit Mode \t\t              \n\n";
        cout << "==================================================================================================\n\n";

        string ClintNumber = GetClientNumber("Enter User Number. Do you want to Deposit Balanced ? ");
        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (size_t i = 0; i + 4 < text.size(); i += 5) {
            clients.push_back(extractClient(text, i));
        }
        Datefromcastomar result = FindClientByAccountNumber(ClintNumber, clients);
        printClient(result);
        bool found = false;
        double depositAmount = GetDepositAmount("Enter Deposit Amount ? ");  // اسم جديد لدالة واضحة وظيفتها

        for (auto& c : clients) {
            if (c.AccountNumber == ClintNumber) {
                found = true;

                if (depositAmount > 0) {
                    c.AccountBalance += depositAmount;
                    cout << "Deposit successful. New balance: " << endl;
                    printClient(c);
                }
                break;
            }
        }

        if (!found) {
            cout << "\nClient not found.\n";
        }
        SaveClientsToFile(clients, "emplyeefile.txt");





        cout << "Do you want to Deposit for another client? (y/n): ";
        cin >> answer;

    } while (tolower(answer) == 'y');
}

void StartToMakeWithdrawClient() {
    char answer;
    do {
        system("cls");
        cout << "==================================================================================================\n\n";
        cout << "\t\t Withdraw Mode \t\t              \n\n";
        cout << "==================================================================================================\n\n";

        string ClintNumber = GetClientNumber("Enter User Number. Do you want to withdraw Balance? ");
        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (size_t i = 0; i + 4 < text.size(); i += 5) {
            clients.push_back(extractClient(text, i));
        }
        Datefromcastomar result = FindClientByAccountNumber(ClintNumber, clients);
        printClient(result);
        bool found = false;
        double WithdrawAmount = GetDepositAmount("Enter Withdraw Amount ? ");

        for (auto& c : clients) {
            if (c.AccountNumber == ClintNumber) {
                found = true;

                if (WithdrawAmount > 0 && c.AccountBalance > WithdrawAmount) {
                    c.AccountBalance -= WithdrawAmount;
                    cout << "Withdraw successful. New balance: " << endl;
                    printClient(c);
                }
                break;
            }
        }

        if (!found) {
            cout << "\nClient not found.\n";
        }
        SaveClientsToFile(clients, "emplyeefile.txt");





        cout << "Do you want to Deposit for another client? (y/n): ";
        cin >> answer;

    } while (tolower(answer) == 'y');
}
void StartToClaTotalBalanced()
{
    system("cls");
    cout << "==================================================================================================\n\n";
    cout << "\t\t Total Balanced Mode \t\t              \n\n";
    cout << "==================================================================================================\n\n";

    string fileContent = ReadFile("emplyeefile.txt");
    vector<string> text;
    splitFunction(fileContent, text, "#//");  // You forgot this

    double TotlalBalanced = 0;

    for (size_t i = 0; i + 4 < text.size(); i += 5) {
        Datefromcastomar client = extractClient(text, i);
        if (client.found) {
            TotlalBalanced += client.AccountBalance;
        }
    }
    StartShowClientList();
    cout << "\nTotal Balance for All Clients: " << TotlalBalanced << " \n";
}

void StartTranScaction()
{
    short chose = 0;
    system("cls");
    cout << "================================================================\n\n";
    cout << "Transaction Menue Screen  \n\n";
    cout << "================================================================\n\n";
    cout << "[1] Depotie \n";
    cout << "[2] Withdraw \n";
    cout << "[3] Total Balacnce \n";
    cout << "[4] Main menue \n";
    cout << "================================================================\n\n";
    cout << "Enter your Chose (1 , 4) ? ";
    cin >> chose;
    switch (chose)
    {
    case(1):
        StartToMakeDepositClient();
        cout << "Press Any Key To Return ...";
        _getch();
        break;
    case(2):
        StartToMakeWithdrawClient();
        cout << "Press Any Key To Return ...";
        _getch();
        break;
    case(3):
        StartToClaTotalBalanced();
        cout << "Press Any Key To Return ...";
        _getch();
        break;
    case(4):
        cout << "Press Any Key To Return ...";
        _getch();

        break;
    default:
        cout << "Un valed Chose ! \n";
    }
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
        cout << "[6] Transaction \n";
        cout << "[7] Mange Users \n";
        cout << "[8] Exit \n";
        cout << "=======================================================================================================\n\n";
        cout << "Enter your Chose ? ";
        cin >> Chose;
        switch (Chose)
        {
        case (1):
            StartShowClientList();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case (2):
            StarttoAddClientinFile();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case (3):
            StarttoDeleteClientFile();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case (4):
            StartEditFanction();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case (5):
            StartToFindClient();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case(6):
            StartTranScaction();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case(7):
            StartSystemUsers(); 
            break; 
        case (8):
            system("cls");
            cout << "===========================================================================================\n\n";
            cout << "\t\tGood Lack \t\t \n\n";
            cout << "===========================================================================================\n\n";
            break;
        default:
            cout << "Un Valied Chose . \n";
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        }


    } while (_getch());
}
void Login() {

    char answer;
    Users result;
    do
    {
        system("cls");
        cout << "==================================================================================================\n\n";
        cout << "\t\t LOGIN \t\t              \n\n";
        cout << "==================================================================================================\n\n";

        string UserName = GetClientNumberUsers("Enter User Name  ? ");
        string password = GetClientNumberUsers("Enter Password ?");
        string fileContent = ReadUsersFileUsers("Users.txt");
        vector<string> text;
        splitFunctionUsers(fileContent, text, "#//");

        vector<Users> clients;
        for (size_t i = 0; i + 2 < text.size(); i += 3) {
            clients.push_back(extractClientUsers(text, i));
        }

        result = FindUsersByAccountNumberAndPassword(UserName, password, clients);
    } while (!result.found);
    StartSystem();
}

int main() {
    Login(); 
}
