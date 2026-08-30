
#include "HASH_MAP.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cout<<"enter number of elements in the array ";
    cin>>n;
    int nums[n];
    cout<<"enter elements into the array ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"enter target number ";
    cin>>target;

    int ans[2]={0};
    HashTable map(n);
    for(int i=0;i<n;i++){
        int complement = target - nums[i];
        
        if(map.search(complement) != -1){
            ans[0] = nums[i];
            ans[1] = complement;
            break;
        }
        else{
            map.insert(nums[i], i);
        }
    }

    cout<<ans[0]<<" "<<ans[1];
}