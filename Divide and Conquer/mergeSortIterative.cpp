#include<iostream>
using namespace std;

int temp[1000];

void Merge(int arr[],int left,int mid,int right)
{
    int i =left;
    int j =mid + 1;
    int k =left;

    while(i<= mid && j<= right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSortIterative(int arr[], int n)
{
    for(int curr_size = 1; curr_size < n; curr_size *= 2)
    {
        for(int left_start = 0; left_start < n-1; left_start += 2 * curr_size)
        {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            Merge(arr, left_start, mid, right_end);
        }
    }
}

void print_arr(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter your array size" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter your array " << endl;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSortIterative(arr, n);

    cout << "Sorted Array:" << endl;
    print_arr(arr, n);

    return 0;
}
