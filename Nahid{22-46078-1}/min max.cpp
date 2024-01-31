///2
///Find the min and max value of the elements of an array:
#include <iostream>
using namespace std;

double arr[5];
double arr1[5];
int Temp = 0;

void arr_swap(double &a,double &b)
    {
        Temp = a;
        a = b;
        b = Temp;
    }
int main()
{
    ///input array
    cout << "Enter 5 number:";
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }

    // Swap adjacent elements and store in arr1
    for (int i = 0; i < 5; i += 2) {
        if (i + 1 < 5) {
            arr_swap(arr[i], arr[i + 1]);
            arr1[i] = arr[i];
            arr1[i + 1] = arr[i + 1];
        } else {
            // odd number,no change
            arr1[i] = arr[i];
        }
    }
    cout << "Swapped array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    cout << "Min value:" << arr[0];
    cout << "Max value:" << arr[5];

    return 0;
}



