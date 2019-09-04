    #include <bits/stdc++.h>
    using namespace std;
     
    #define MAX 10000000
     
    // sqrt(n) factorization
    void sqrtn(int n) {
    	printf("Sqrt(n) Prime Factorization: \n");
    	for(int i=2; i*i<=n; i++) {
    		if(n%i == 0) {
    			int cnt = 0;
    			while(n%i == 0) {
    				cnt++;
    				n /= i;
    			}
    			printf("%d^%d ", i, cnt);
    		}
    	}
     
    	// only one prime factor greater than sqrt(n) can exist
    	if(n != 1) {
    		printf("%d^1", n);
    	}
    }
     
    int sprime[MAX+5];
    void sieve() {
     
    	for(int i=2; i<=MAX; i++) {
    		sprime[i] = i;
    	}
     
    	for(int i=2; i*i<=MAX; i++) {
    		if(sprime[i] == i) {
    			for(int j=i*i; j<=MAX; j+=i) {
    				sprime[j] = min(sprime[j],i);
    			}
    		}
    	}
    }
     
    // log(n) factorization
    void logn(int n) {
    	printf("Log(n) Prime Factorization: \n");
    	int sp = sprime[n];
    	while(n > 1) {
    		int sp = sprime[n];
    		int cnt = 0;
    		while(n%sp == 0) {
    			n /= sp;
    			cnt++;
    		}
    		printf("%d^%d ", sp, cnt);
    	}
    }
     
    int main() {
    	int n;
    	cin>>n;
    	sqrtn(n);
    	printf("\n");
     
    	sieve();
    	logn(n);
    	printf("\n");
    	return 0;
    }