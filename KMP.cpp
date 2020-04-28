// KMP algorithm for counting occurences of key in word ( nlogn )

#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;

ll lcps[100001];                        //Array to store the length of longest prefix that is also a suffix
void createLCPS(string &key){
    ll n=key.length();
    lcps[0]=0;
    for(ll j=1;j<n;j++){
        ll i=lcps[j-1];
        while(i>0 && key[i]!=key[j]){
            i=lcps[i-1];
        }
        if(key[i]==key[j]){
            lcps[j]=i+1;
        }else{
            lcps[j]=0;
        }
    }
    lcps[n]=0;
}

ll countOcc(string &txt,string &key){
    ll n=txt.length(),len=key.length(),cnt=0;
    ll pos=0;
    for(ll i=0;i<n;i++){
        while(pos>0 && txt[i]!=key[pos]){
            pos=lcps[pos-1];
        }
        if(txt[i]==key[pos]){
            pos++;
        }
        if(pos==len){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    string txt="coding is rising",key="ing";
    createLCPS(key);
    ll occ = countOcc(txt,key);
    cout<<occ;
}
