ll power(ll x, ll y) { 
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

ll inv(ll x){
	return power(x,mod-2);
}
