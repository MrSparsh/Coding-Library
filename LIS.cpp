#include <bits/stdc++.h>
using namespace std;
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n, diff) for (ll i = k; i < n; i += diff)
#define debug2(x, y) cout << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define debug3(x, y, z) cout << #x << " :: " << x << "\t" << #y << " :: " << y << "\t" << #z << " :: " << z << endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
typedef long long ll; typedef pair<ll, ll> pl; typedef vector<ll> vl; typedef vector<pl> vpl; typedef vector<vl> vvl; typedef vector<vpl> vvpl;
const ll mod = 1000000007;

int lis(vl &arr) {
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
    ll n;
    cin>>n;
    vl v{4,2,3,5,7,8,1,2};
    cout<<lis(v);
}