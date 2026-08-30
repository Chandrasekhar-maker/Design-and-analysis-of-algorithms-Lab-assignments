
#include "HASH_MAP.h"
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of elements in the array ";
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    HashTable map(n);
    for(int i=0;i<n;i++){
        int key=nums[i];
        int currentFreq=map.search(key);

        
        if(currentFreq == -1) {
            map.insert(key, 1);
            
        } else {

            map.insert(key, currentFreq + 1);
        }
        
    }
    map.displayFrequencies(map);
}