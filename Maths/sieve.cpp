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