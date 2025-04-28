#include <string>
#include <iostream>
#include <vector>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
void splitfanction(string S1 , vector <string > &text  , string dime )
{
	int token =0; 
	;
	short pos = 0;
	string word; 
	while ((pos = S1.find(dime)) != std::string::npos)
	{
		token++;
		word = S1.substr(0, pos);
		if (word != dime)
		{
			text.push_back(word);
			
		}
		S1.erase(0, pos + dime.length());
	}
	if (S1 != "")
	{
		token++;
		text.push_back(S1);
	}
	cout << "Token = " << token <<endl ; 
}
void printresulats(const vector <string > &text )
{
	for (const string &word : text)
	{
		cout << word << endl;
	}
}
int main()
{
	string S1= ReadString();
	vector <string > text;
	
	splitfanction(S1, text ,",");
	printresulats(text);
	system("pause>0");
}