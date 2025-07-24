#include <iostream>
using namespace std;

int countComparisons=0;

int partition(int arr[], int low, int high) {
    int pivot =arr[low];
    int i =low;
    int j =high;

    while (i<j) {
        while (i<=high&&arr[i]<= pivot) {
            i++;
            countComparisons++;
        }

        while (j >= low && arr[j] > pivot) {
            j--;
            countComparisons++;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSortIterative(int arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int p = partition(arr,low,high);

        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortIterative(arr,0,n - 1);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons:" << countComparisons << endl;

    return 0;
}
