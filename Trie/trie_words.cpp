#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(ll i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define loop2(i,k,n,diff) for(ll i=k;k<n?i<=n:i>=n;k<n?i+=diff:i-=diff)
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

void printVec(vl&,ll n);
void print2DVec(vvl &vv,ll n,ll m);

struct TrieNode{
    TrieNode* chld[26];
    bool isVal;
    TrieNode(){
        for(int i=0;i<26;i++){
            chld[i]=NULL;
        }
        isVal=false;
    }
};

void insert(string word,TrieNode* root) {
    TrieNode* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            curr->chld[ch-'a']=new TrieNode();
        }
        curr=curr->chld[ch-'a'];
    }
    curr->isVal=true;
}

bool search(string &word,TrieNode* root) {
    TrieNode* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            return false;
        }
        curr=curr->chld[ch-'a'];
    }
    return curr->isVal;
}
    

int main() {
	boost;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	


    return 0;
}

void printArr(ll &arr,ll n){
    loop(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void print2DArr(vvl &mat,ll n,ll m){
    loop(i,0,n){
        loop(j,0,m){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}