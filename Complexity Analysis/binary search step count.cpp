#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int step=0;

    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            step ++;

            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<"After Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i] <<" ";
    }

    cout<<endl;

}
int binarySearch(int arr[], int n, int number)
{
    int low=0;
    int high=n-1;
    int steps = 0;

    while(low <= high)
    {
        steps++;
        int mid =(low + high)/2;

        if(arr[mid] == number)
        {
            cout <<"steps in Binary Search: " <<steps<<endl;
            return mid;
        }
        else if(arr[mid]<number)
        {
            low=mid+1;
        }

        else
        {
             high=mid-1;
        }
    }

    return -1;
}

int main() {

    int n,number;
    cout << "Enter your array size" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter your array " << endl;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout<<"Enter number for Search "<<endl;

    cin>>number;

    int index= binarySearch(arr, n, number);

    if(index != -1)
    {
        cout<<"Number id found, index is: "<<index+1<<endl;
    }
    else
    {
        cout<<"Number is Not Found: "<<endl;
    }

    return 0;
}

