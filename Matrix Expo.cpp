    #include <bits/stdc++.h>
    using namespace std;
     
    #define mod 1000000007
     
    long long result[2][2]={{1,1},{1,0}};
    long long transformation[2][2]={{1,1},{1,0}};
    void matrixMul(long long a[2][2],long long b[2][2])
    {
    	 int i,j,k;
    	 long long re[2][2] ={0};
    	 for(i=0;i<2;i++) {
    	 	for(j=0;j<2;j++) {
    	 		for(k=0;k<2;k++) {
    	 			re[i][j] = (re[i][j] + (a[i][k]*b[k][j])%mod ) % mod;
    	 		}
    	 	}
    	 }
    	 for(i=0;i<2;i++)
    	 {
    	 	for(j=0;j<2;j++)
    	 	result[i][j]=re[i][j];
    	 }
    }
     
    void initialize() {
    	result[0][0]=result[0][1]=result[1][0]=1;
    	result[1][1]=0;
    }
    void power(int n)
    {
    	if(n==1)
    	return ;
    	power(n/2);
    	matrixMul(result,result);
    	if(n&1)
    	{
    		matrixMul(result,transformation);
    	}
    }
     
    int main()
    {
    	initialize();
    	int n;
    	cin>>n;
     
    	if(n == 0 || n == 1) {
    		printf("Nth fibonacci = %d\n", n);	
    	}
    	else {
    		power(n-1);
    		printf("Nth fibonacci = %lld\n", result[0][0]);
    	}
    	return 0;
    }