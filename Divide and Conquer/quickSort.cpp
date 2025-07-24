#include<iostream>
using namespace std;

int stepCount = 0;

void Swap(int *a, int *b)
{
   int temp=*a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int l, int h)
{
    int pivot=arr[l];
    int i=l;
    int j=h;

    while(i<j)
    {
        while(i<=h && arr[i]<=pivot)
        {
            i++;
            stepCount++;

        }

        while(j>=l && arr[j] >pivot)
        {
            j--;
            stepCount++;
        }

        if(i<j)
        {
            Swap(&arr[i],&arr[j]);
        }

    }
   Swap(&arr[l],&arr[j]);
   return j;
}

void quick_sort(int arr[], int l, int h)
{
    if(l<h)
    {
        int j=Partition(arr, l,h);
        quick_sort(arr,l, j-1);
        quick_sort(arr,j+1,h);

    }
}



int main()
{

    int n;
    cout<<"Enter your array size"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter your array "<<endl;

    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    quick_sort(arr,0,n-1);

    cout<<"quick Sorted "<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    cout << "Number of comparisons (steps): " << stepCount << endl;

}
