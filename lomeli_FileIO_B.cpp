#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    string firstName, lastName;
    double num1, num2, num3, num4, num5, num6, average, sum;
    double maxAve = 0;
    string maxName;
    ifstream fin;
    ofstream fout;
    char fileName[12];
    cout << "Please enter name of file: ";
    cin >> fileName;
    
    fin.open(fileName);
    if(fin.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);   
    }//if
    fout.open("results.txt");
    if(fout.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }//if
    while(fin >> firstName >> lastName >> num1 >> num2 >> num3 >> num4 >> num5 >> num6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        average = ((num1 + num2 + num3 + num4 + num5 + num6) / 6);
        
        fout << setw(12) << firstName << setw(12)  << lastName ;
        //fout.setf(ios::right);
        fout << setw(8) << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << average <<endl;
    if(average > maxAve)
    {
        maxAve = average;
        maxName = firstName + " " + lastName;
    }//if
    }//while
    fout << "Highest Score: " << maxName << endl;
    
    fin.close();
    fout.close();
    return 0;
}//main

