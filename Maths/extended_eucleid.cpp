// Used to solve equation of the form ax+by=c where c is the multiple of gcd(a,b)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> solveHelper(ll a,ll b){
    if(b==0){
        return make_pair(1,0);
    }
    pair<ll,ll> ans=solveHelper(b,a%b);
    ll x=ans.first;
    ll y=ans.second;
    return make_pair(y,x-a/b*y);
}

pair<ll,ll> solve(ll a,ll b,ll c){
    ll gcd=__gcd(a,b);
    a=a/gcd;
    b=b/gcd;
    c=c/gcd;
    pair<ll,ll> ans=solveHelper(a,b);
    return make_pair(c*ans.first,c*ans.second);
}

int main(){
    ll a=3,b=5,c=30;                                        //Suppose Equation is 3x+5y=30
    pair<ll,ll> ans = solve(a,b,c);                         //It will return a pair containing ans to (x,y)
    cout<<"x= "<<ans.first<<"   y="<<ans.second<<endl;      
}