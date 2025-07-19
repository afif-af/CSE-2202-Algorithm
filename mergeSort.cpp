#include<iostream>
using namespace std;
int temp[1000];

void Merge(int arr[], int p, int mid, int r)
{
    int i=p;
    int j=mid+1;
    int k=p;

    while(i<=mid && j<=r)
    {

        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {

            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j<=r)
    {
        temp[k] = arr[j];
        j++;
        k++;

    }
    for (int i=p; i<=r; i++)
    {
        arr[i] = temp[i];
    }

}



void mergeSort(int arr[], int p, int r)
{
    if (p<r)
    {
        int mid = (p+r)/2;
        mergeSort(arr,p,mid);
        mergeSort(arr,mid+1,r);
        Merge(arr,p,mid,r);
    }
}

void print_arr(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
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

    mergeSort(arr,0,n-1);

    print_arr(arr,n);

    return 0;
}

