#include<bits/stdc++.h>
#define ll long long
using namespace std;
class DiophantineEquation{
    ll a,b,c;
    public:
    DiophantineEquation(ll a,ll b,ll c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    pair<ll,ll> solve(ll a,ll b){
        if(b==0){
            return make_pair(1,0);
        }
        pair<ll,ll> ans=solve(b,a%b);
        ll x=ans.first;
        ll y=ans.second;
        return make_pair(y,x-a/b*y);
    }
    pair<ll,ll> solveEquation(){
        ll gcd=__gcd(a,b);
        a=a/gcd;
        b=b/gcd;
        c=c/gcd;
        pair<ll,ll> ans=solve(a,b);
        return make_pair(c*ans.first,c*ans.second);
    }
};

int main(){
    DiophantineEquation eq(4,6,10);
    pair<ll,ll> ans = eq.solveEquation();
    cout<<ans.first<<" "<<ans.second;
    return 0;
}