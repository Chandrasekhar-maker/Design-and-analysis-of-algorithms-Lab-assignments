
#include<bits/stdc++.h>
using namespace std;

pair<int,int> findbounds(int a[],int low,int high){
      if(low==high){
          return {a[low],a[low]};
      }
      if(high==low+1){
          return {max(a[low],a[high]),min(a[low],a[high])};
      }
      
      int mid=low+(high-low)/2;
      int max1,min1,max2,min2;

      tie(max1,min1)=findbounds(a,low,mid);
      tie(max2,min2)=findbounds(a,mid+1,high);

      return {max(max1,max2),min(min1,min2)};
}

int main(){
    int a[7]={1,7,9,3,67,5,2};
    int ma,mi;
    tie(ma,mi) = findbounds(a,0,6);
    cout<<"maximun element is "<<ma<<" minimum element is "<<mi;

    return 0;
}