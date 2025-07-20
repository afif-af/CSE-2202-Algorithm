#include<iostream>

using namespace std;

int knapsack(int capacity,int weight[], int val[], int n)
{
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++)
    {

        for(int w=0;w<=capacity;w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w)
            {
                dp[i][w]=max(val[i-1] + dp[i-1][w-weight[i-1]],dp[i-1][w]);

            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }

        }
    }
    return dp[n][capacity];

}

int main()
{

    int n,capacity;
    cout<<"Enter the size of value "<<endl;
    cin>>n;
    cout<<"Enter the knapsack capacity "<<endl;
    cin>>capacity;
    int val[n], weight[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value"<<endl;
        cin>>val[i];
        cout<<"Enter the weight"<<endl;
        cin>>weight[i];

    }
    cout<<"Maximum value in knapsack "<<knapsack(capacity,weight,val,n)<<endl;

}
