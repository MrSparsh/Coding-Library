// Calculating LIS in nlogn using set

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lis(vector<ll> &arr) {
   set<int> st;
   for(int i=0;i<arr.size();i++){
       auto it = st.upper_bound(arr[i]);
       if(it==st.end()){
           st.insert(arr[i]);
       }else{
           st.erase(it);
           st.insert(arr[i]);
       }
   }
   return st.size();
   
}

int main(){
    vector<ll> v{4,2,3,5,7,8,1,2};
    cout<<lis(v);
}