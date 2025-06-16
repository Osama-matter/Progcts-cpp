#include<iostream> 
using namespace std; 
class Person 
{
	int   _Id; 
	
	string _FristName; 
	string _LastName; 
	string _FullName; 

	string _Email; 
	string _Phone;

	string _Massage; 

public:

	
	Person(int Id, string FristName, string LastName, string FullName, string Email, string Phone)
	{
		_Id = Id; 
		_FristName = FristName; 
		_LastName = LastName; 
		_FullName = FullName; 

		_Email = Email; 
		_Phone = Phone; 
 
	}

	void SetID(int Id)
	{
		_Id = Id; 
	}
	int GetID()
	{
		return _Id; 
	}
	void SetFristName(string FristName)
	{
		_FristName = FristName; 
	}
	void SetLastName(string LastName)
	{
		_LastName = LastName; 
	}

	void SetEmail(string Email)
	{
		_Email = Email; 
	}
	void SetPhone(string Phone)
	{
		_Phone = Phone; 
	}

	string GetFristName()
	{
		return _FristName; 
	}
	string GetLastName()
	{
		return _LastName; 
	}

	string GetEmail()
	{
		return _Email; 
	}
	string GetPhone()
	{
		return _Phone; 
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
	virtual  void Print() //  Virtual Functions Using when useing Upcasting And OverReading Fanction  to avoid a output erorr  , 
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
 //inthirtance Class  generate new class Inhirit all charactric of a old class you can add what you wont  ; 
class Emplyoee :public  Person 
{
private :
	int _Salary; 
	string _Title;
	string _DepartMAent;
public:
	Emplyoee(int Id, string FristName, string LastName, string FullName, string Email, string Phone , string Title, string DepartMaent,  int Salary)
		:Person(Id, FristName, LastName, FullName, Email, Phone)
	{
		_Title = Title; 
		_DepartMAent = DepartMaent; 
		_Salary = Salary; 

	}
	int GetSalary()
	{
		return _Salary;
	}	
	string GetTitle()
	{
		return _Title;
	}
	string GetDepartMent()
	{
		return _DepartMAent;
	}
	void SetSalary(int Salary)
	{
		_Salary = Salary;
	}
	void SetTitle(string Title)
	{
		_Title = Title;
	}
	void SetDepartMaent(string DepartMent)
	{
		_DepartMAent = DepartMent;
	} 
	// Overeep Fanction Using a inthirtance Class When Super Class have a same Fanction ;   
	void Print()
	{
		cout << "\n--------------------------------------------\n";
		cout << "ID          " << GetID()  << endl;
		cout << "Frist Name  " << GetFristName() << endl;
		cout << "Last Name   " << GetLastName() << endl;
		cout << "Full Name   " << FullName() << endl;
		cout << "Title       " << _Title <<endl ;
		cout << "Department  " << _DepartMAent << endl; 
		cout << "Salary      " << _Salary << endl; 
		cout << "Enail       " << GetEmail() << endl;
		cout << "Phone       " << GetPhone() << endl;
		cout << "----------------------------------------------\n\n";
	}
};

class Programmer :public Emplyoee
{
private:
	string _MainProgramingLanguch; 


public:
	Programmer(int Id, string FristName, string LastName, string FullName, string Email, string Phone, string Title, string DepartMaent,string MainProgramingLanguch ,  int Salary)
		:Emplyoee(Id, FristName, LastName, FullName, Email, Phone, Title, DepartMaent, Salary)
	{
		_MainProgramingLanguch = MainProgramingLanguch;
	}
	void SetMainProgramingLanguch(string MainProgramingLanguch)
	{
		_MainProgramingLanguch = MainProgramingLanguch; 
	}
	string GetMainPrograminLangutch()
	{
		return _MainProgramingLanguch; 
	}
	void Print()
	{
		cout << "\n--------------------------------------------\n";
		cout << "ID                      " << GetID() << endl;
		cout << "Frist Name              " << GetFristName() << endl;
		cout << "Last Name               " << GetLastName() << endl;
		cout << "Full Name               " << FullName() << endl;
		cout << "Title                   " << GetTitle() << endl;
		cout << "Department              " << GetDepartMent() << endl;
		cout << "Main Programing Languch " << _MainProgramingLanguch << endl; 
		cout << "Salary                  " << GetSalary() << endl;
		cout << "Enail                   " << GetEmail() << endl;
		cout << "Phone                   " << GetPhone() << endl;
		
		cout << "----------------------------------------------\n\n";
	}
};
 

int main()
{	 
	Emplyoee Emplyee1(1, "Osama ", "matter ", "Osama Matter ", "osamamatter390@gmail.com ", "01273201805", "CEO", "Soft Ware DevolpMent", 100000); 

	Emplyee1.Print(); 

	Emplyee1.SendEmail("Hi", "How Are you");
	Emplyee1.SenSMS("YOu are great ");
	cout << "\n-------------------------------------------------------\n"; 
	Programmer Programmer1(1, "Osama ", "matter ", "Osama Matter ", "osamamatter390@gmail.com ", "01273201805", "CEO", "Soft Ware DevolpMent" ,  "C++", 100000);
	Programmer1.Print(); 
 


	// UpCasting Using a based Class to acsee element in a drived class  .
	// Static Early Bunginig  compilar know adress in a compliar time  Fast  .  
	Person* person1 = &Emplyee1; 
	cout << person1->FullName() << endl; 

	// ex2
	Emplyoee* employee1 = &Programmer1;
	cout << employee1->GetPhone() << endl; 


	//Virtual Functions 
	// Dynamic LataBiniding Compilar know Adress in a run time  . Slow  
	Person* Person3 = &Emplyee1; 
	Person3->Print();
	Person* person3 = &Programmer1; 
	person3->Print(); 

}

///Inhettance can  you mak it priivt or public or protected ; 
// Public can acess every hink in a super class  ;
// Privit not able to acsee any thine in a super class  ; 
// protectied can acess a member in a drived class anot able to acess it outSide class  ; 