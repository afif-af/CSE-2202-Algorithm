#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    int steps = 0;
    int found=0;

    for(int i = 0; i < n; i++) {
        steps++;
        if(arr[i] == key) {
            found++;

            cout<<"Number is found, index is "<<i+1<<endl;
            break;
        }
    }

    cout <<"steps in Linear Search: " << steps << endl;

    if (found =0)
    {
        cout<<"Not found Number"<<endl;

    }



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
    int num;
    cout<<"Enter your search number "<<endl;
    cin>>num;

    linearSearch(arr,n,num);

    return 0;
}
