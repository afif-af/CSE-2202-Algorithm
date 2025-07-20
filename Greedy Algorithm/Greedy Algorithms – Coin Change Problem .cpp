#include<iostream>
#include<math.h>

using namespace std;

void Sort(int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}

void greedy(int arr[], int n, int amount)
{
    Sort(arr,n);

    int Count=0;

    cout << "\nCoins used:\n";
    for(int i=0; i<n;i++)
    {
        while(amount>=arr[i])
        {
            amount=amount-arr[i];
            Count++;
            cout<<arr[i]<<" ";

        }

    }
    cout<<"the number of coin is: "<<Count;
}

int main()
{
    int n, amount;

    cout<<"Enter the amount: ";
    cin>>amount;

    cout<<"Enter how many coin you want to insert: ";
    cin>>n;
    int arr[1000];

    cout<<"Enter the value of coin: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    greedy(arr,n,amount);

    return 0;
}
