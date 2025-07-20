#include<iostream>
#include<math.h>
using namespace std;

void sorRatio(double Ratio[],double value[],double weights[], double n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(Ratio[i]<Ratio[j])
            {
                double temp=Ratio[i];
                Ratio[i]=Ratio[j];
                Ratio[j]=temp;

                temp=value[i];
                value[i]=value[j];
                value[j]=temp;

                temp=weights[i];
                weights[i]=weights[j];
                weights[j]=temp;



            }
        }
    }

    cout<<"Sorted value to weight ratios "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<Ratio[i] <<" " <<endl;
    }
}

void knapsack(double n, double capacity, double weight[], double value[])
{
    double total_value=0.0;
    double Remaining_capacity=capacity;
    double fraction;

    for(int i=0;i<n;i++)
    {
        if(weight[i]<=Remaining_capacity)
        {

            total_value+=value[i];
            Remaining_capacity-=weight[i];

        }
        else
        {
            fraction=Remaining_capacity/weight[i];
            total_value+=value[i]*fraction;
            Remaining_capacity=0;
            break;
        }
    }
    cout<<endl;
    cout<<total_value;



}

int main()
{
    double value[10],weight[10],n,capacity;
    double Ratio[10];

    cout<<"Enter number of items ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Item "<<i+1 <<"- value: ";
        cin>>value[i];

        cout<<"Item "<<i+1 <<"- weight: ";
        cin>>weight[i];

    }

    cout<<"Enter the weight ";
    cin>>capacity;

    for(int i=0; i<n;i++)
    {
        Ratio[i]=value[i]/weight[i];
    }

    sorRatio(Ratio,value,weight,n);
    knapsack(n,capacity,weight,value);

}
