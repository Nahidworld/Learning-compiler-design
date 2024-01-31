///1
///Find the average value do the elements of an array.*/
#include <iostream>
using namespace std;

double arr[5];
double sum=0, avg=0;

int main()
{
    //arrayinput();
    cout << "Enter 5 number:";
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        //cout<<endl;
    }

    for(int i=0; i<5; i++)
    {
        sum = sum + arr[i];
    }
    avg = sum/5;
    cout << avg;

    return 0;
}


