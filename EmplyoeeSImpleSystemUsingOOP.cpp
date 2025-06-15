#include<iostream> 
using namespace std; 
class Employee
{
	int   _Id; 
	int _Salary;
	string _FristName; 
	string _LastName; 
	string _FullName; 
	string _Title;
	
	string _DepartMAent;
	string _Email; 
	string _Phone;

	string _Massage; 

public:
	
	Employee(int Id, string FristName, string LastName, string FullName, string Title, string DepartMaent, string Email, string Phone, int Salary)
	{
		_Id = Id; 
		_FristName = FristName; 
		_LastName = LastName; 
		_FullName = FullName; 
		_Title = Title; 
		_DepartMAent = DepartMaent; 
		_Email = Email; 
		_Phone = Phone; 
		_Salary = Salary; 
	}

	void SetID(int Id)
	{
		_Id = Id; 
	}
	void SetFristName(string FristName)
	{
		_FristName = FristName; 
	}
	void SetLastName(string LastName)
	{
		_LastName = LastName; 
	}
	void SetTitle(string Title )
	{
		_Title = Title; 
	}
	void SetDepartMaent(string DepartMent)
	{
		_DepartMAent = DepartMent; 
	}
	void SetEmail(string Email)
	{
		_Email = Email; 
	}
	void SetPhone(string Phone)
	{
		_Phone = Phone; 
	}
	void SetSalary(int Salary)
	{
		_Salary = Salary; 
	}
	string GetFristName()
	{
		return _FristName; 
	}
	string GetLastName()
	{
		return _LastName; 
	}
	string GetTitle()
	{
		return _Title; 
	}
	string GetDepartMent()
	{
		return _DepartMAent; 
	}
	string GetEmail()
	{
		return _Email; 
	}
	string GetPhone()
	{
		return _Phone; 
	}
	int GetSalary()
	{
		return _Salary; 
	}
	string FullName()
	{
		return _FristName + "  "  + _LastName; 
	}

	void SendEmail(string Subject, string Body)
	{
 
		cout << "The Follwoing email Has Send successful to email " << _Email  <<" \n"; 
		cout << "Subiect :" << Subject <<endl ;
		cout << "Body :" << Body << endl << endl ; 
		
	}
	void SenSMS(string Massage)
	{
	 
		cout << "The Follwoing SMS has Send successful to phone " << _Phone << "  \n"; 
		cout << Massage << endl; 
	}
	void Print()
	{
		cout << "\n--------------------------------------------\n"; 
		cout << "ID          " << _Id <<endl ;
		cout << "Frist Name  " << _FristName << endl; 
		cout << "Last Name   " << _LastName << endl; 
		cout << "Full Name   " << _FullName << endl;
		cout << "Title       " << _Title << endl; 
		cout << "DepartMent  " << _DepartMAent << endl; 
		cout << "Salary      " << _Salary << endl; 
		cout << "Enail       " << _Email << endl;
		cout << "Phone       " << _Phone << endl; 
		cout << "----------------------------------------------\n\n"; 
	}

};
int main()
{
	Employee Person1 ( 1  , "Osama", "Matter ", "Osama Ahmed Matter ", "Jnior FullStack devolver", "WebDevolpment " , "osamamatter390@gmail.com", "01273201805", 15000);
	Person1.Print(); 
	Person1.SendEmail("Hi", "How Are you"); 
	Person1.SenSMS("YOu are great "); 
}