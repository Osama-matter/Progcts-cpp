#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 
#include <string>
#include <ctime>
using namespace std;

string GetStringData()
{
	string Date = " "; 
	cout << "Enter Data Day / Month / Year :"; 
	getline(cin, Date); 
	return Date; 
}
bool splitFunction(string content, vector<string>& result, string delimiter)
{
	
	
	size_t pos = 0;
	while ((pos = content.find(delimiter)) != string::npos) {
		string token = content.substr(0, pos);
		if (!token.empty()) result.push_back(token);
		content.erase(0, pos + delimiter.length());
	}
	if (!content.empty()) result.push_back(content);

	if (result.size() != 3) {
		cout << "Invalid date format! Please enter as Day/Month/Year.\n";
		return false;
	}
	cout << "\n---------------------------------------\n"; 
	cout << "Day : " << result[0] <<endl ; 
	cout << "Month : " << result[1] << endl; 
	cout << "Year : " << result[2] << endl;
	return true; 
}
struct sDate
{
	int Day; 
	int Month; 
	int Year; 
};
sDate ConvertToInt(vector<string> result  )
{
	sDate Date; 
	Date.Day = stoi(result[0]); 
	Date.Month = stoi(result[1]); 
	Date.Year = stoi(result[2]); 
	return Date; 
}
int main()
{
	sDate Data; 
	
	vector<string> result;
	string content; 
	content = GetStringData();
	splitFunction(content, result, "/"); 
	Data = ConvertToInt(result);
	cout << "\n---------------------------------------\n";
	cout << "Data  : " << Data.Day << " / " << Data.Month << " / " << Data.Year << endl; 

}


