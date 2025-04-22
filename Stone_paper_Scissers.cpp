#include<iostream>
#include<cstdlib>
using namespace std;
enum enchose { Stone = 1, Paper = 2, Scisser = 3 };
void ifplyerwonttoplayagine(int& chose, int& choserandowm, int& numberround, int& user, int& computer, int& notwinner); // use it when use faction in fanction but it comes after her 
void  Getchose(int& chose)
{



	cout << "Enter chose : [1]Stone _ [2] Paper _ [3] Scissors ? " << endl;
	cin >> chose;

}
enchose  Getchosefromuser(int& chose)
{
	if (chose == enchose::Paper)
	{
		cout << "Player Chose : Paper  \n ";
	}
	else if (chose == enchose::Scisser)
	{
		cout << "Player Chose : Scisser  \n ";
	}
	else if (chose == enchose::Stone)
	{
		cout << "Player Chose : Stone  \n ";
	}
	else
	{
		cout << "Rong chose !!  \n ";
		system("color 4f");
		system("echo \a");
	} 
	return enchose::Scisser;
}
int randowmnumber(int from, int to)
{
	int randoim = rand() % (to - from + 1) + from;
	return randoim;
}
void GetchoseBycomputer(int& choserandowm)
{

	choserandowm = randowmnumber(1, 3);
	if (choserandowm == 2)
	{
		cout << "Computer Chose : Paper  \n ";
	}
	else if (choserandowm == 3)
	{
		cout << "Computer Chose : Scisser  \n ";
	}
	else if (choserandowm == 1)
	{
		cout << "Computer Chose : Stone  \n ";
	}
}
void  comperchose(int chose, int choserandowm, int& user, int& computer, int& notwinner)
{

	if (chose == choserandowm)
	{
		cout << "Not Winner !!  \n ";
		system("color 6f");
		notwinner++;
	}
	else if (chose == 1 && choserandowm == 2)
	{
		cout << "computer  is winner \n";
		system("color 4f ");
		system("echo \a");
		computer++;
	}
	else if (chose == 3 && choserandowm == 1)
	{
		cout << "computer  is winner \n";
		system("color 2f ");
		user++;
	}
	else if (chose == 2 && choserandowm == 3)
	{
		cout << "computer  is winner \n";
		system("color 4f ");
		system("echo \a");
		computer++;
	}
	else if (chose == 3 && choserandowm == 2)
	{
		cout << "You Are Winner  \n";
		system("color 4f ");
		system("echo \a");
		computer++;
	}
	else if (chose == 1 && choserandowm == 3)
	{
		cout << "You Are  Winner \n";
		system("color 2f ");
		user++;
	}
	else if (chose == 2 && choserandowm == 1)
	{
		cout << "You Are winner \n";
		system("color 2f ");
		user++;
	}

}
void printresulat(int  numberround, int user, int computer, int notwinner)
{
	cout << "                ----------------------------------------------------------------\n ";
	cout << "                                  +++Game Over +++                    \n \n ";
	cout << "                ----------------------------------------------------------------\n \n ";
	cout << "                ---------------------Game Results---------------------------------\n ";
	cout << "                 Game Round       :" << numberround << "\n ";
	cout << "                 Player won times :" << user << endl;
	cout << "                 computer won times :" << computer << endl;
	cout << "                 Not Winner won times :" << notwinner << endl;
	cout << "                ----------------------------------------------------------------\n ";
}
void numberofround(int& chose, int& choserandowm, int& numberround, int& user, int& computer, int& notwinner)
{

	cout << "Enter the number of Round ? \n  ";
	cin >> numberround;
	for (int i = 0; i < numberround; i++)
	{
		Getchose(chose);
		cout << "-------------------Round [" << i + 1 << "]--------------------- \n \n ";
		Getchosefromuser(chose);
		GetchoseBycomputer(choserandowm);
		comperchose(chose, choserandowm, user, computer, notwinner);
		cout << "---------------------------------------------------------------------------\n \n ";

	}
	printresulat(numberround, user, computer, notwinner);
	ifplyerwonttoplayagine(chose, choserandowm, numberround, user, computer, notwinner);
}
void  ifplyerwonttoplayagine(int& chose, int& choserandowm, int& numberround, int& user, int& computer, int& notwinner)
{
	bool answer = 0;
	cout << "Do you wont to play Agin ( [1]_ yes  [0]_ No )  \n ";
	cin >> answer;
	if (answer == 1)
	{
		numberofround(chose, choserandowm, numberround, user, computer, notwinner);
	}
	else
	{
		return;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int chose;
	int choserandowm;
	int numberround;
	int user = 0;
	int computer = 0;
	int notwinner = 0;
	numberofround(chose, choserandowm, numberround, user, computer, notwinner);

	return 0;
}
