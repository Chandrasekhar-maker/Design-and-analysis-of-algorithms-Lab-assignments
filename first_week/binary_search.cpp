
#include<bits/stdc++.h>
using namespace std;

int binary(int a[],int s,int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]==s)
            return mid;
        else if(a[mid]>s)
            r=mid-1;
        else if(a[mid]<s)
            l=mid+1;
    }
    return -1;
}
int main(){
    int n;

    cout<<"enter size of the array : ";

    cin>>n;
    int arr[n];
    cout<<"enter elements into the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int c=1;
    cout<<"continue this search only if array is sorted. to continue enter 1 if not enter 0.  : ";
    cin>>c;
    if(c==0){
        return 0;
    }
    int s;
    cout<<"enter element to be search :";
    cin>>s;
    
   
    binary(arr,s,n)!=-1?cout<<"element is fount at "<<binary(arr,s,n):cout<<"element is not found";

    return 0;
}