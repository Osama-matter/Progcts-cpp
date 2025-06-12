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
Datefromcastomar CurrentClient; 

Datefromcastomar Login();



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
Datefromcastomar FindUsersByAccountNumberAndPassword(const string& UserName, const string& Password, const vector<Datefromcastomar>& clients) {
    for (const auto& c : clients) {
        if (c.AccountNumber == UserName && c.AccountPassword == Password) {
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
    cout << "Do you wont to Edit User (y /n) ?  \n";
    cin >> chose;
    return (chose == 'y' || chose == 'Y');
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
    for (int i = 0; i < text.size(); i += 5)
    {
        p = extractClient(text, i);
        printClient(p);
    }
}

void StartToMakeDepositClient() {
    system("cls");
    cout << "==================================================================================================\n\n";
    cout << "\t\t Deposit Mode \t\t              \n\n";
    cout << "==================================================================================================\n\n";

    string ClintNumber = CurrentClient.AccountNumber;
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
    double depositAmount = GetDepositAmount("Enter Deposit Amount ? ");

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
}
void starttoShowWithDrawList()
{

    cout << "===========================================\n";
    cout << "\t\tQucik Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance;
}
int ReadAmomuntOfWithDraw()
{
    short choose= 0 ; 
    starttoShowWithDrawList();
    cout << "\nEnter youer Choose [ 1 , 9 ] ?";
    cin >>choose; 
    return choose; 

}
int ReturnAmountOFChiose()
{
    int choose = ReadAmomuntOfWithDraw(); 
    switch (choose)
    {
    case(1):
        return 20; 
        break; 
    case(2):
        return 50; 
        break; 
    case(3):
        return 100; 
        break; 
    case(4):
        return 200; 
        break; 
    case (5):
        return 400; 
        break; 
    case(6):
        return 600;
        break; 
    case(7):
        return 800;
        break; 
    case(8):
        return 1000; 
        break; 
    case(9):

        system("cls"); 
        break; 
    }
    
}

void StartToMakeWithdrawClient() {
    system("cls");
    cout << "==================================================================================================\n\n";
    cout << "\t\t Withdraw Mode \t\t              \n\n";
    cout << "==================================================================================================\n\n";

    string ClintNumber = CurrentClient.AccountNumber;
    string fileContent = ReadFile("emplyeefile.txt");
    vector<string> text;
    splitFunction(fileContent, text, "#//");

    vector<Datefromcastomar> clients;
    for (size_t i = 0; i + 4 < text.size(); i += 5) {
        clients.push_back(extractClient(text, i));
    }
    Datefromcastomar result = FindClientByAccountNumber(ClintNumber, clients);

    bool found = false;

    double WithdrawAmount;

    for (auto& c : clients) {
        if (c.AccountNumber == ClintNumber) {
            found = true;
            WithdrawAmount = ReturnAmountOFChiose();
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


}
void StartToMakeNormalWithdrawClient() {
    system("cls");
    cout << "==================================================================================================\n\n";
    cout << "\t\t Withdraw Mode \t\t              \n\n";
    cout << "==================================================================================================\n\n";

    string ClintNumber = CurrentClient.AccountNumber;
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

    int  WithdrawAmount;
    for (auto& c : clients) {
        if (c.AccountNumber == ClintNumber) {
            found = true;
            do
            {

                WithdrawAmount = GetDepositAmount("Enter Withdraw Amount ? ");

            } while (!(WithdrawAmount > 0 && c.AccountBalance > WithdrawAmount && WithdrawAmount % 100 == 0));

            c.AccountBalance -= WithdrawAmount;
            cout << "Withdraw successful. New balance: " << endl;
            printClient(c);

            break;
        }
    }

    if (!found) {
        cout << "\nClient not found.\n";
    }
    SaveClientsToFile(clients, "emplyeefile.txt");

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
    
    cout << "\nTotal Balance for All Clients: " << TotlalBalanced << " \n";
}

void StartttoATM()
{
    do
    {
        short chose = 0;
        system("cls");
        cout << "================================================================\n\n";
        cout << "ATM System   \n\n";
        cout << "================================================================\n\n";
        cout << "[1] Depotie \n";
        cout << "[2] Withdraw \n";
        cout << "[3] Normal Withdraw \n";
        cout << "[4] Total Balacnce \n";
        cout << "[5] Exit \n";
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
            StartToMakeNormalWithdrawClient();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case(4):
            StartToClaTotalBalanced();
            cout << "Press Any Key To Return ...";
            _getch();
            break;
        case(5):
            system("cls");
            Login();
            break;

       
        default:
            cout << "Un valed Chose ! \n";
            _getch();
        }
    } while (true);
}
Datefromcastomar Login() {

   
    Datefromcastomar result;
    result.found = true;
    do
    {
        system("cls");
        cout << "==================================================================================================\n\n";
        cout << "\t\t LOGIN \t\t              \n\n";
        cout << "==================================================================================================\n\n";
        if (!result.found)
        {
            cout << "Unvaled User Name , Password . \n";
        }
        string UserName = GetClientNumber("Enter User Name  ? ");
        string password = GetClientNumber("Enter Password ?");
        string fileContent = ReadFile("emplyeefile.txt");
        vector<string> text;
        splitFunction(fileContent, text, "#//");

        vector<Datefromcastomar> clients;
        for (size_t i = 0; i + 2 < text.size(); i += 5) {
            clients.push_back(extractClient(text, i));
        }

        result = FindUsersByAccountNumberAndPassword(UserName, password, clients);
    } while (!result.found);

    return result;
}
int main()
{
    CurrentClient =  Login();
    StartttoATM(); 

}
