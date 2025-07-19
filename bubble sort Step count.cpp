#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n) {
    int steps = 0;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            steps++;
            if(arr[j]>arr[j+1]) {

                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout << "Total steps " << steps << endl;
}

int main() {
    int n;
    cout<<"Enter your array size"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter your array "<<endl;

    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);

    cout<<"Bubble Sorted "<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}

