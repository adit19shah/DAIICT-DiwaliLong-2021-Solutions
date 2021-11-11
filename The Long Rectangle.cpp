/*
            ************************
            ************************
            ***   ADIT SHAH      ***
            ***   DA-IICT        ***
            ***   ramanujan_19   ***
            ************************
            ************************
*/
#include<bits/stdc++.h>
using namespace std;
#define fr(x,s,e) for(ll x = s; x < e; ++x)
#define ll long long int
#define ld long double
#define imx 1e18
#define imn -1e18
#define pb push_back
#define pll pair<ll,ll>
#define vl vector<ll>
#define ff first
#define ss second
#define bl bool
#define tr true
#define fl false
#define all(v) v.begin(),v.end()
#define eps 1e-9;   //Epsilon value below which approximate floating type number as 0
#define mod1 1000000007
#define mod2 998244353
#define jadap ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vector<vl> dp(1000000+1,vl(4));
void pre(){
    dp[1][0]=1;
    dp[1][2]=1;
    fr(i,2,1000000+1){
        fr(j,0,4){
            dp[i][0]+=dp[i-1][j];
            if(j==3)
                dp[i][0]+=2*dp[i-1][j];
            dp[i][0]%=mod1;
        }
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        dp[i][2]=dp[i][0];  //same calculation as for dp[i][0]
        fr(j,2,4){
            dp[i][3]+=dp[i-1][j];
            if(j==3)
                dp[i][3]+=2*dp[i-1][j];
            dp[i][3]%=mod1;
        }
    }
}
void solve(ll z){
    ll n; cin>>n;
    ll x=0;
    fr(j,0,4){
        x+=dp[n][j];
        if(j==3){
            x+=2*dp[n][j];
        }
        x%=mod1;
    }
    cout<<x<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    jadap;
    int T=1;
    cin>>T;
    pre();
    fr(z,0,T){
        solve(z);
    }
    return 0;
}