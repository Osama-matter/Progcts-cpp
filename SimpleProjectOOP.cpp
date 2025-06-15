#include<iostream> 
using namespace std; 
class Info
{
	string  _Id; 
	string _FristName; 
	string _LastName; 
	string _FullName; 
	string _Email; 
	string _Phone;

	string _Massage; 

public:

	Info(string Id  , string FristName , string LastName  , string FullName  , string Email , string Phone  )
	{
		_Id = Id; 
		_FristName = FristName; 
		_LastName = LastName; 
		_FullName = FullName; 
		_Email = Email; 
		_Phone = Phone; 
	}
	void setFristName(string FristName)
	{
		_FristName = FristName;
	}
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	void SetFullName(string FullName)
	{
		_FullName = FullName;
	}
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string FristName()
	{
		
		return _FristName; 
	}

	string  ID()
	{
		//SetID(ID); Read only property ;  
		return _Id; 
	}

	string LastName(string)
	{
		
		return _LastName; 

	}

	string FullName()
	{
 
		return _FullName; 
	}

	string Email( )
	{
 
		return _Email; 
	}

	string Phone(string Phone )
	{
		SetPhone(Phone); 
		return _Phone; 
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
		cout << "Enail       " << _Email << endl;
		cout << "Phone       " << _Phone << endl; 
		cout << "----------------------------------------------\n\n"; 
	}

};
int main()
{
	Info Person1 ( "A101" , "Osama", "Matter ", "Osama Ahmed Matter ", "osamamatter390@gmail.com", "01273201805");
	Person1.Print(); 
	Person1.SendEmail("Hi", "How Are you"); 
	Person1.SenSMS("YOu are great "); 
}
