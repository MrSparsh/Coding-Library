#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long> 
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
using namespace std;

ll n,q,arr[30001],bs,mp[1000001],res[200001];
ll cl=0,cr=0,ans=0;
vector<pair<pll,int> >v;

bool cmp(pair<pll,int> p1,pair<pll,int> p2){
    if(p1.first.first/bs == p2.first.first/bs){
        return p1.first.second>p2.first.second;
    }
    return p1.first.first/bs < p2.first.first/bs;
}

void add(ll idx){
    mp[arr[idx]]++;
    if(mp[arr[idx]]==1){
        ans++;
    }
}

void rem(ll idx){
    mp[arr[idx]]--;
    if(mp[arr[idx]]==0){
        ans--;
    }
}

int main() {
	cin>>n;
	bs=sqrt(n);
	for(int i=0;i<n;i++){cin>>arr[i];}
	cin>>q;
	for(int i=0;i<q;i++){
	    ll l,r;
	    cin>>l>>r;
	    l--,r--;
	    v.push_back(make_pair(make_pair(l,r),i));
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<q;i++){
	    ll nl=v[i].first.first,nr=v[i].first.second;
	    ll qno=v[i].second;
	    while(cl<nl){
	        rem(cl);
	        cl++;
	    }
	    while(cl>nl){
	        add(cl-1);
	        cl--;
	    }
	    while(cr<=nr){
	        add(cr);
	        cr++;
	    }
	    while(cr>nr+1){
	        rem(cr-1);
	        cr--;
	    }
	    res[qno]=ans;
	}
	for(int i=0;i<q;i++){
	    cout<<res[i]<<endl;
	}
}



