#include<iostream>
using namespace std;

int nthFiboU(int n, int memo[])
{
    if(n<=1)
    {
        return n;
    }
    if(memo[n] != -1)
    {
        return memo[n];
    }
    memo[n]=nthFiboU(n-1, memo)
            +nthFiboU(n-2, memo);

    return memo[n];
}

int nthFibo(int n)
{
    int memo[n+1];
    for(int i=0;i<=n;i++)
    {
        memo[i]=-1;

    }
    return nthFiboU(n, memo);
}


int main()
{
    int n;
    cout<<"Enter number of sequance "<<endl;
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        cout<<nthFibo(i) <<" ";
    }
    return 0;

}

