#include<iostream>
#include <vector>
using namespace std ; 
int GetNUmber()
{
    int  number =0 ; 
    do
    {
        cout <<"Enter Number ? \n" ;
        cin >> number ;
    } while (number<=0);
    return number  ; 
}
void GenerateFibonaccinumbers( vector <int > &Fibonaccinumber ,  int number  )
{
   
    int val1 =0 ; 
    int val2 =0 ;
    int sum1 = 0 ;
    int sum2 =0 ;
   
    for (int i = 0 ; i< number  ; i++)
    {
        sum1 = val1 + val2 ;
        val1 = val2 ;
        val2 = i  ;
        sum2 = sum1 + val2 ;
        Fibonaccinumber[i] = sum2  ;  
    } 
}
void printresulats(vector <int > Fibonaccinumber)
{
    for (int &num  :Fibonaccinumber)
    {
        cout << num << "    " ;
    }
}
int main ()
{
    int number  ;
    vector <int > Fibonaccinumber ;
    GetNUmber() ; 
    GenerateFibonaccinumbers(Fibonaccinumber ,number) ;
    printresulats(Fibonaccinumber) ;

}