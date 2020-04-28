// BIT implemented for computing prefix-sum 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll BIT[500001],n;    //Take care to change the size of tree as per question

// idx is 1-indexed
void update(ll idx,ll val){
    while(idx<=n){
        BIT[idx]+=val;
        idx=idx+(idx&(-idx));
    }
}
ll query(ll idx){
    ll ans=0;
    while(idx>0){
        ans+=BIT[idx];
        idx=idx-(idx&(-idx));
    }
    return ans;
}
void printBIT(){
    for(ll i=1;i<=n;i++) cout<<BIT[i]<<" ";
    cout<<endl;
}

int main(){
    n=5;
    ll arr[6];                                          
    arr[1]=3,arr[2]=6,arr[3]=4,arr[4]=5,arr[5]=7;       // 1-indexed
    for(ll i=1;i<=n;i++) update(i,arr[i]);
    printBIT();
}