
#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;
enum enlevel { easy = 1, mid = 2, hard = 3, veryhard = 4 };
enum enoppertion { Add = 1, sub = 2, Div = 3, Min = 4, mix = 5 };
void  Doyouwonttoplayagin(char& answer, int numberround, int type, enoppertion op, int chose, int num1, int num2, int user, int computer);
enoppertion getRandomOperation()
{
	return (enoppertion)(rand() % 4 + 1); // يرجع Add, sub, Div, Min
}
char operationSymbol(enoppertion op)
{
	switch (op) {
	case Add: return '+';
	case sub: return '-';
	case Div: return '/';
	case Min: return '*';
	default:  return '?';
	}
}
enoppertion typeofopperation(int& type)
{

	cout << "Enter Type of oppreation 1[ + ] , 2[ * ] , 3[ / ] . 4[ - ] , 5[ All of them ] \n ";
	cin >> type;
	cout << "____________________________________________________________\n ";
	return (enoppertion)type;
}
enlevel  Getlevelfromuser(int& chose)
{

	cout << "Enter level of sum 1_[Easy] , 2_[Mid] , 3_[hard] , 4_[veryhard]  \n  ";
	cin >> chose;
	return (enlevel)chose;
}
int  Howmanynumberofqu()
{
	int  roundnumber;
	cout << "Enter Number of Round ? \n  ";
	cin >> roundnumber;
	return roundnumber;
}
int randowmnumber(int from, int to)
{
	int randoim = rand() % (to - from + 1) + from;
	return randoim;
}

void    sumresulats(int  type , enoppertion &op)
{
	switch (type)
	{
	case (Add):
		cout << " + \n ";
		break;
	case (sub):
		cout << " * \n ";
		break;
	case (Div):
		cout << " / \n ";
		break;
	case (Min):
		cout << "  - \n ";
		break;
	case (mix):
		cout <<operationSymbol(op) << "\n ";
		break;
	default:
		break;
	}
}
enoppertion  printtypeoppreation(int type )
{
	switch (type)
	{
	case Add:
		return enoppertion::Add;
		break;
	case sub:
		return enoppertion::sub;
		break;
	case Div:
		return enoppertion::Div;
		break;
	case Min:
		return enoppertion::Min;
		break;
	case mix:
		return getRandomOperation();
		break;
	default:
		break;
	}
}

int   Generatenumber(int chose, int type, int& num1, int& num2 , enoppertion op)
{
	switch (chose)
	{
	case(easy):
		num1 = randowmnumber(1, 9);
		cout << num1 << endl;
		sumresulats(type ,op);
		num2 = randowmnumber(1, 9);
		cout << num2 << endl;
		break;
	case (mid):
		num1 = randowmnumber(21, 30);
		cout << num1 << endl;
		sumresulats(type , op );
		num2 = randowmnumber(21, 30);
		cout << num2 << endl;
		break;
	case(hard):
		num1 = randowmnumber(41, 50);
		cout << num1 << endl;
		sumresulats(type  ,op );
		num2 = randowmnumber(41, 50);
		cout << num2 << endl;
		break;
	case (veryhard):
		num1 = randowmnumber(51, 60);
		cout << num1 << endl;
		sumresulats(type ,op );
		num2 = randowmnumber(51, 60);
		cout << num2 << endl;
		break;
	default:
		return 0;
		break;
	}
}
int claoppretion(int num1, int num2, enoppertion& op)
{
	switch (op)
	{
	case enoppertion::Add:
		return num1 + num2;
		break;
	case enoppertion::sub:
		return num1 * num2;
		break;
	case enoppertion::Div:
		return num1 / num2;
		break;
	case enoppertion::Min:
		return num1 - num2;
		break;
	case enoppertion::mix:
		return  0;
		break;
	default:
		break;
	}
}
void GetAnswerfromuser(int num1, int  num2, enoppertion op ,int &user  , int &computer  )
{

	int resulat = 0;
	int sum = claoppretion(num1, num2, op);
	cout << "------------------------------------------------\n ";
	cout << "Enter resulat ? \n ";
	cin >> resulat;
	if (resulat == sum )
	{
		cout << "True --) \n ";
		system("color 2f ");
		user ++ ;
		cout << "----------------------------------------------------\n ";
	}
	else
	{
		cout << "False )-- \n ";
		cout << "true :" << sum  << endl;
		system("color 4f ");
		computer++;
		cout << "----------------------------------------------------\n ";

	}
}
void printresulat( int user, int computer , int numberround)
{
	cout << "                ----------------------------------------------------------------\n ";
	cout << "                                  +++Game Over +++                    \n \n ";
	cout << "                ----------------------------------------------------------------\n \n ";
	cout << "                ---------------------Game Results---------------------------------\n ";
	cout << "                 Game Round       :" << numberround << "\n ";
	cout << "                 Player won times :" << user << endl;
	cout << "                 computer won times :" << computer << endl;
	cout << "                ----------------------------------------------------------------\n ";
}
void StartGame(int &numberround  , int &type ,enoppertion &op ,int &chose ,int &num1 , int &num2  , int user , int computer  ,char &answer   )
{
	cout << "Enter number of round ? \n ";
	cin >> numberround;
	typeofopperation(type);
	op = printtypeoppreation(type);
	Getlevelfromuser(chose);
	for (int i = 1; i <= numberround; i++)
	{
		cout << "-------------------Round [" << i  << "]--------------------- \n \n ";
		Generatenumber(chose, type, num1, num2 , op);
		GetAnswerfromuser(num1, num2, op, user, computer);
	}
	printresulat(user, computer , numberround);
	Doyouwonttoplayagin( answer,numberround, type, op, chose, num1, num2, user, computer);
}
void  Doyouwonttoplayagin( char &answer ,int numberround, int type, enoppertion op, int chose, int num1, int num2, int user, int computer)
{
	cout << "Do you wont to play agin (Y : N)  ? \n  ";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		system("cls");
		StartGame(numberround, type, op, chose, num1, num2, user, computer ,answer);
	}
	else 
	{
		return  ;
	}
}
int main()
{
	srand(static_cast<unsigned int>(time(0))); 
	enoppertion op;
	int type;
	int chose;
	int num1, num2;
	int user =0 , computer = 0 ;
	int numberround; 
	char answer;
	StartGame(numberround, type, op, chose, num1, num2, user, computer,answer);
	return 0;
}