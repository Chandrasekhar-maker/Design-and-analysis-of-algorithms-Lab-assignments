
#include<bits/stdc++.h>
using namespace std;
int formula(int a,int n,int r){
    return (a*(pow(r,n)-1))/(r-1);
}

int iterative(int a,int n,int r){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+a;
        a=a*r;
    }
    return sum;
}

int main(){
    int a,n,r;
    cout<<"enter first value ";
    cin>>a;
    cout<<"enter  common ratio of the series";
    cin>>r;
    cout<<"enter number of term in the geometric progression";
    cin>>n;
    cout<<"through formula method using in bulit functin "<<formula(a,n,r)<<endl;;
    cout<<"through iterative method "<<iterative(a,n,r);
}
