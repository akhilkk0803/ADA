/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[],int target,int i,int n){
    if(i==n)return false;
    if(arr[i]==target)return true;
    return linearSearch(arr,target,i+1,n);
}
bool binarySearch(int arr[],int target,int lb,int ub){
    if(lb>ub)return false;
    int mid=(lb+ub)/2;
    if(arr[mid]==target)return true;
    if(arr[mid]>target)return binarySearch(arr,target,lb,mid-1);
    else return binarySearch(arr,target,mid+1,ub);
}
void input(){
    for(int i=100;i<=1000;i+=100){
        int arr[i];
        for(int j=0;j<i;j++){
            arr[j]=rand()%i;
        }
        clock_t start_ls=clock();
        linearSearch(arr,-1,0,i);
        clock_t end_ls=clock();
        sort(arr,arr+i);
        clock_t start_bs=clock();
        binarySearch(arr,-1,0,i-1);
        clock_t end_bs=clock();
        double time_ls=(double)((end_ls-start_ls))/1000;
        double time_bs=(double)((end_bs-start_bs))/1000;
        cout<<"time for "<<i<<" inputs ls: "<<time_ls<<endl;
        cout<<"time for "<<i<<" inputs bs: "<<time_bs<<endl;
    }
}
int main()
{
    input();
    
    return 0;
}
