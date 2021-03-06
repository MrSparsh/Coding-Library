// Mo's Algo to calclate no distinct integers in range (l,r) in n^(3/2)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,q,arr[30001],bs,hsh[1000001],res[200001];
ll cl=0,cr=0,ans=0;
vector<pair<pair<ll,ll>,ll> >v;

bool comp(pair<pair<ll,ll>,ll> p1,pair<pair<ll,ll>,ll> p2){
    if(p1.first.first/bs == p2.first.first/bs){
        return p1.first.second>p2.first.second;
    }
    return p1.first.first/bs < p2.first.first/bs;
}

void add(ll idx){
    hsh[arr[idx]]++;
    if(hsh[arr[idx]]==1){
        ans++;
    }
}

void rem(ll idx){
    hsh[arr[idx]]--;
    if(hsh[arr[idx]]==0){
        ans--;
    }
}

ll main() {
	cin>>n;
	bs=sqrt(n);
	for(ll i=0;i<n;i++){cin>>arr[i];}
	cin>>q;
	for(ll i=0;i<q;i++){
	    ll l,r;
	    cin>>l>>r;
	    l--,r--;
	    v.push_back(make_pair(make_pair(l,r),i));
	}
	sort(v.begin(),v.end(),comp);
	for(ll i=0;i<q;i++){
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
	for(ll i=0;i<q;i++){
	    cout<<res[i]<<endl;
	}
}



