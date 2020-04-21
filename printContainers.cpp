#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(ll i=k;i<=n;i+=1)
#define loop2(i,k,n,diff) for(ll i=k;i<=n;i+=diff)
#define ll long long
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
typedef pair<ll, ll>	pl;
typedef vector<ll>		vl;
typedef vector<pl>		vpl;
typedef vector<vl>		vvl;
const ll mod = 1000000007;

void printArr(ll *arr,ll n){
    loop(i,0,n) cout<<arr[i]<<" ";
    cout<<endl;
}

void print2DArr(ll **mat,ll n,ll m){
    loop(i,0,n){
        loop(j,0,m) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void printVec(vl &vec,ll n){
    loop(i,0,n) cout<<vec[i]<<" ";
    cout<<endl;
}

void print2DVec(vvl vv,ll n,ll m){
    loop(i,0,n){
        loop(j,0,m) cout<<vv[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main() {
	boost;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	


    return 0;
}

