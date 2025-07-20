#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int coinRow(vector<int>& coin)
{
    int n=coin.size();
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return coin[0];
    }

    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=coin[0];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],coin[i-1]+dp[i-2]);

    }

    return dp[n];

}

int main()
{
    int n;
    cout<<"Enter size of coin list: ";
    cin>>n;

    vector<int>coin(n);
    cout<<"Enter the coin values:\n ";
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    cout<<"using dynamic programming ";
    cout<<coinRow(coin)<<endl;


}

