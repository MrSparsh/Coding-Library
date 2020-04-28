// Sparse Table to calculate range max query

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


ll n,sparse[200001][18];
void preprocess(ll a[]){
  for(int i=0;i<n;i++){sparse[i][0]=a[i];}
  for(int j=1;(1<<j)<=n;j++){
    for(int i=0;i+(1<<j)-1<n;i++){
      sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
    }
  }
}
ll query(ll l,ll r){
  int diff=log2(r-l+1);
  return max(sparse[l][diff],sparse[r-(1ll<<diff)+1ll][diff]);
}
void printTable(){
  for(int i=0;i<n;i++){
    for(int j=0;i+(1<<j)-1<n;j++){
      cout<<sparse[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  ll arr[]={5,4,8,1,9,2,5,7,1,6,8};
  n=11;
  preprocess(arr);
  printTable();
  return 0;
}
