
#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[], int p[], int i,int u, int dp[][100]){
    if(i==0 || u==0){
        return 0;
    }
    if(dp[i][u]!=-1){
        return dp[i][u];
    }
    if(w[i]>u){
         dp[i][u]=knapsack(w,p,i-1,u,dp);
    }
    else{
         
        int include= p[i]+knapsack(w,p,i-1,u-w[i],dp);
        int exclude= knapsack(w,p,i-1,u,dp);

       dp[i][u]= max(include,exclude);
    }

    return dp[i][u];
   
}

int main(){
    
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int w[n+1],p[n+1];
    w[0]=0;
    cout<<"Enter the weights of items: ";
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    p[0]=0;
    cout<<"Enter the profits of items: ";
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int u;
    cout<<"Enter the capacity of knapsack: ";
    cin>>u;
    int dp[100][100];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=u;j++){
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(w,p,n,u,dp)<<endl;
}
