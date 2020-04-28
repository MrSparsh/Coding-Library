// Fast Exponentiation in logn
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll fast_expo(ll x, ll y) { 
	ll res=1; 
	x=x%mod; 
	while(y>0){
		if(y & 1){
			res=(res*x)%mod;
		}
		y=y>>1; 
		x=(x*x)%mod;
	} 
	return res; 
}

ll inv(ll x){								//Return (x^(-1))%mod
	return fast_expo(x,mod-2);
}

int main(){
	cout<<fast_expo(3,4)<<endl;		//3^4
	cout<<inv(3)<<endl;				//(3^(-1))%mod
}