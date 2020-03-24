//Find no of numbers from l to r such that occurences of 
// digit(0) = digit(9)
// digit(1) = digit(8)
// digit(2) = digit(7)
// digit(3) = digit(6)
// digit(4) = digit(5)


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 15;
vector<int> dig;
ll dp[M][M][M][M][M][M][2][2];
ll call(int pos,int d0,int d1,int d2,int d3,int d4,int tight,int start){
    if(d0<0 || d0>14 ||d1<0 || d1>14 ||d2<0 || d2>14 ||d3<0 || d3>14 ||d4<0 || d4>14){return 0;}
    if(pos==dig.size()){
        return (d0==7) && (d1==7) && (d2==7) && (d3==7) && (d4==7) && !start;
    }
    if(dp[pos][d0][d1][d2][d3][d4][tight][start]!=-1){return dp[pos][d0][d1][d2][d3][d4][tight][start];}
    ll lmt,cans=0;
    if(tight){lmt=dig[pos];}else{lmt=9;}
    for(int i=0;i<=lmt;i++){
        int nt=tight;
        if(tight && i<lmt){
            nt=0;
        }
        if(!start && i==0){
            cans+=call(pos+1,d0-1,d1,d2,d3,d4,nt,0);
        }else if(i==1){
            cans+=call(pos+1,d0,d1-1,d2,d3,d4,nt,0);
        }else if(i==2){
            cans+=call(pos+1,d0,d1,d2-1,d3,d4,nt,0);
        }else if(i==3){
            cans+=call(pos+1,d0,d1,d2,d3-1,d4,nt,0);
        }else if(i==4){
            cans+=call(pos+1,d0,d1,d2,d3,d4-1,nt,0);
        }else if(i==5){
            cans+=call(pos+1,d0,d1,d2,d3,d4+1,nt,0);
        }else if(i==6){
            cans+=call(pos+1,d0,d1,d2,d3+1,d4,nt,0);
        }else if(i==7){
            cans+=call(pos+1,d0,d1,d2+1,d3,d4,nt,0);
        }else if(i==8){
            cans+=call(pos+1,d0,d1+1,d2,d3,d4,nt,0);
        }else if(i==9){
            cans+=call(pos+1,d0+1,d1,d2,d3,d4,nt,0);
        }else{
            cans+=call(pos+1,d0,d1,d2,d3,d4,nt,1);
        }
    }
    return dp[pos][d0][d1][d2][d3][d4][tight][start]=cans;
}
ll solve(ll n){
    dig.clear();
    memset(dp,-1,sizeof(dp));
    while(n){
        dig.push_back(n%10);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
    return call(0,7,7,7,7,7,1,1);
}
int main() {
    ll l,r;
    cin>>l>>r;
    cout<<solve(r)-solve(l-1);
}
