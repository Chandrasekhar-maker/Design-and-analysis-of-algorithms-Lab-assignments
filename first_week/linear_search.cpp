
#include<bits/stdc++.h>
using namespace std;

int linear(int a[],int s,int n){
    for(int i=0;i<n;i++){
        if(a[i]==s)
            return i;
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter size of the array :";
    cin>>n;
    int arr[n];
    cout<<"enter elements into the array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s;
    cout<<"enter element to be search :";
    cin>>s;
    
    linear(arr,s,n)!=-1?cout<<"element is fount at "<<linear(arr,s,n):cout<<"element is not found";
}