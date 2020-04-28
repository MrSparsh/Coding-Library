// Matrix Expo for calculating nth Fibonacci in logn

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll result[2][2]={{1,1},{1,0}};						//Matrix to store result
ll transformation[2][2]={{1,1},{1,0}};				//Matrix to store the matrix for which exponent has to be calculated
void matrixMul(ll a[2][2],ll b[2][2])
{
	int i,j,k;
	ll re[2][2] ={0};
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			for(k=0;k<2;k++) {
				re[i][j] = (re[i][j] + (a[i][k]*b[k][j])%mod ) % mod;
			}
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++) result[i][j]=re[i][j];
	}
}
	
void initialize() {									//Call this everytime before calling matrix_expo()
	result[0][0]=result[0][1]=result[1][0]=1;
	result[1][1]=0;
}
void matrix_expo(int n)								// Computes res^n and stores it in res
{
	if(n==1) return;
	matrix_expo(n/2);
	matrixMul(result,result);
	if(n&1)
	{
		matrixMul(result,transformation);
	}
}
	
int main()
{
	initialize();
	ll n=4;
	if(n == 0 || n == 1) {
		cout<<n<<"th fibonacci = "<<n<<endl;	
	}
	else {
		matrix_expo(n-1);
		cout<<n<<"th fibonacci = "<<result[0][0]<<endl;
	}
	return 0;
}