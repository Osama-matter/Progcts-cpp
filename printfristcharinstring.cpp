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
    bool isfiristnumber =true; 
    cout <<"Frist number in string .  ";
    for (int i = 0 ;i<s1.length() ;i++ )
    {
        if (s1[i] != ' '  &&isfiristnumber )
        {
            cout << s1[i] <<"   " ; 
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