#include<iostream >
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Datefromcastomar
{
	string AccountNumber;
	string  AccountPassword;
	string Name;
	string Number;
	int AccountBalance;
};
Datefromcastomar GetData(Datefromcastomar& p1)
{
	cout << "Enter Account NUmber ? ";
	getline(cin>>ws , p1.AccountNumber);
	cout << "\nEnter Account Possaword  ? ";
	getline(cin , p1.AccountPassword);
	cout << "\nEnter Name ? ";
	getline(cin , p1.Name);
	cout << "\nEnter Your Number ? ";
	getline(cin , p1.Number);
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
void Printresulatsinfile(Datefromcastomar p1, string  dime , string S2)
{
	fstream myfile;
	myfile.open("emplyeefile.txt", ios::out |ios::app);
	if (myfile.is_open())
	{
		S2 =MakeDatainString(p1, S2, "#//");
		myfile << S2 << endl;
	}
}
void ifuserwonttoAddextra(Datefromcastomar p1, string dime, string S2)
{
	char answer = ' ';
	do
	{
		system("cls");
		GetData(p1);
		
		Printresulatsinfile(p1, "#//", S2);
		cout << "Do you wont to Add (y/n) \n";
		cin >> answer;
		answer = tolower(answer);
	} while (answer == 'y');
}
int main()
{
	Datefromcastomar p1;
	string S2;
	ifuserwonttoAddextra(p1, "#//", S2);
	return 0 ;
	
}