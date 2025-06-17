//Polymorphism make Fanction  have to uses for Ex  1_Fanction OverLoading , fanction  Overriding  , Virtual Fanction , operator Overloading  ;  
// Abstrct class OR  interface Class  Make it to define fantion do  you need to implement this in Drived class inhetanes this class  
// frind class make class can acess privet member inside a drived class  , frind faction make fanction can ascess all memebers  in super class  ; 

#include<iostream>
using namespace std;
class ConnectPerson
{
	virtual void SendEmail() = 0; 
	virtual void SendSms() = 0; 
	virtual void ConectUs() = 0; 
};
class Person : public ConnectPerson 
{
private :
	string _fristName;
	string _LastName; 
public:
	void SendEmail()   // Pure Virtual fanction . 
	{

	};
	void SendSms()
	{

	};
	void ConectUs()
	{

	};
	Person(string fristName, string LastName)
	{
		_fristName = fristName;
		_LastName = LastName; 
	}
	void SetFristname(string FristName)
	{
		_fristName = FristName; 
	}
	void SetLastName(string LastName)
	{
		_LastName = LastName; 
	}
	string GetFristName()
	{
		return _fristName; 
	}
	string GetLastName()
	{
		return _LastName; 
	}
	virtual void Print() // virtual Fanction 
	{
		cout << "\n---------------------------------------\n"; 
		cout << "Frist Name  : " << _fristName << endl; 
		cout << "Last  Name  : " << _LastName << endl;
		cout << "\n----------------------------------------\n"; 
	}
	
	friend  class Programmer; 
	friend  void printPersonData(Person P1);  

};
class Programmer :public Person
{
private :
	string _Title;
	string _Department; 
	int _Salary; 
public:
	Programmer(string fristName, string LastName, string Title, string Department, int  Salary)
		:Person(fristName, LastName)
	{
		_Title = Title; 
		_Department = Department; 
		_Salary = Salary; 
	}
	void SetTitle(string Title)
	{
		_Title = Title; 
	}
	void SetDepartment(string Department)
	{
		_Department = Department; 
	}
	void SetSalary(int Salary)
	{
		_Salary = Salary; 
	}
	string GetTitle()
	{
		return _Title; 
	}
	string GetDeparment()
	{
		return _Department; 
	}
	int GetSalary()
	{
		return _Salary; 
	}
	void Print() // OVerrding
	{
		cout << "\n---------------------------------------\n";
		cout << "Frist Name  : " << GetFristName() << endl;
		cout << "Last  Name  : " << GetLastName() << endl;
		cout << "Title       : " << _Title << endl; 
		cout << "DepartMent  : " << _Department << endl; 
		cout << "Salary      :" << _Salary << endl; 
		cout << "\n----------------------------------------\n";

	}

	void printprivitmember(Person A1)
	{
		cout << A1._fristName; 
	}

};
void printPersonData(Person P1)
{
	cout << P1._fristName << endl ; 
}
int main()
{
	
	Person person1("Osama ", "Matter");
	person1.Print(); //virtual Fanction ; 
	

	Programmer employee1("Osama", "Matter ", "Software Devolper", "Web Devolment ", 100000); 
	employee1.Print(); // Overriding Fanction  ;


	printPersonData(person1); 
}
