#include <bits/stdc++.h>
using namespace std;
 
int x, y;
int gcdex(int a, int b) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
 
	int x1, y1;
	int gcd = gcdex(b, a%b);
	x1 = x, y1 = y;
 
	x = y1;
	y = (x1 - (a/b)*y1);
	return gcd;
}
 
int main() {
	int p, q;
	cin>>p>>q;
 
	int gcd = gcdex(p, q);
	printf("x = %d, y = %d, gcd = %d\n", x, y, gcd);
}