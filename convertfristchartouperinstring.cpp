#include <iostream>
#include<string>
using namespace std; 
string Getname ()
{
    string s1 = " " ; 
    cout << "Enter youer name ? \n" ;
    getline(cin , s1) ;
    return s1 ;

}
void checkANdPrintresulat (string &s1  )
{
    char c1  = ' ';
    int number =0  ;
    bool isfiristnumber =true; 
    cout <<"Frist number in string .  ";
    for (int i = 0 ;i<s1.length() ;i++ )
    {
        if (s1[i] != ' '  &&isfiristnumber )
        {
            c1 = s1[i] +32;
            cout << c1 ;
            
        }
        else
        {
            cout << s1[i] ; 
        }
        isfiristnumber=(s1[i]==' ' ? true : false );
    }
}
int main ()
{
   
   string name =Getname() ;
    checkANdPrintresulat(name) ;
    return 0 ; 
}
// to convert char to upper char - 32 
// (32)  number to upper case + lower case ; 
