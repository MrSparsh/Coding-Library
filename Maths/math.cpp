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

ll minP[1000001];
void sieve(ll n) {
    
    for(ll i=2; i<=n; i++) {
        minP[i] = i;
    }
    
    for(ll i=2; i*i<=n; i++) {
        if(minP[i] == i) {
            for(ll j=i*i; j<=n; j+=i) {
                minP[j] = min(minP[j],i);
            }
        }
    }
}
     
void factorize(ll n) {
    ll sp = minP[n];
    while(n > 1) {
        ll sp = minP[n];
        ll cnt = 0;
        while(n%sp == 0) {
            n /= sp;
            cnt++;
        }
        cout<<sp<<"^"<<cnt<<" ";
    }
}