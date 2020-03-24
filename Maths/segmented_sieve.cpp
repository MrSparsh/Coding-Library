
ll MAX=1000000;
void sieve(){
	for(int i=2; i<=MAX; i++) {
		sprime[i] = i;
	}
	for(int i=2; i*i<=MAX; i++) {
		if(sprime[i] == i) {
			for(int j=i*i; j<=MAX; j+=i) {
				sprime[j] = i;
			}
		}
	}
	for(ll i=2;i<=MAX;i++){
	    if(sprime[i]==i){
	        primes.push_back(i);
	        //cout<<i<<" ";
	    }
	}
}
void seg_sieve(ll l,ll r){
	int isP[r-l+1];
	memset(isP,1,sizeof(isP));
	for(ll i:primes){
        ll st=ceil(1.0*l/i)*i;
        st = st>=l?2*st:st;
        for(ll j=st;j<=r;j+=i){
            isP[j-l]=0;
        } 
    }
}
int main(){
	sieve();
}