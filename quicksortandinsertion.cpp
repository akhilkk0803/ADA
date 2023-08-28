/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int>arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1])swap(arr[j],arr[j-1]);
        }
    }
}
int partition(vector<int>&arr,int lb,int ub){
    int pivot=arr[lb];
    int i=lb+1,j=ub;
    while(i<=j){
        while(i<=j and arr[i]<=pivot)i++;
        while(i<=j and arr[j]>=pivot)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[lb],arr[j]);
    return j;
}
void quickSort(vector<int>&arr,int lb,int ub){
    if(lb>=ub)return;
    int p=partition(arr,lb,ub);
    quickSort(arr,lb,p-1);
    quickSort(arr,p+1,ub);
}
void input(){
    for(int i=100;i<=1000;i+=100){
        vector<int>arr(i);
        for(int j=0;j<i;j++){
            arr[j]=rand()%i;
        }
        clock_t start_is=clock();
        insertion(arr);
        clock_t end_is=clock();
        clock_t start_qs=clock();
        quickSort(arr,0,i-1);
        clock_t end_qs=clock();
        double time_is=(double)((end_is-start_is))/1000;
        double time_qs=(double)((end_qs-start_qs))/1000;
        cout<<"time for "<<i<<" inputs InsertionSort: "<<time_is<<endl;
        cout<<"time for "<<i<<" inputs Quicksort: "<<time_qs<<endl;
 }
} 
int main()
{
   input();
    return 0;
}
