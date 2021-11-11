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
void solve(ll z){
    ll n;
    cin>>n;
    vl v(n);
    fr(i,0,n)  cin>>v[i];
    ll h; cin>>h;
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    sort(all(v));
    ll x=min({abs(v[n-1]-h)+abs(v[n-1]-v[1]),abs(v[1]-h)+abs(v[1]-v[n-1]),abs(v[0]-h)+abs(v[n-2]-v[0]),abs(h-v[n-2])+abs(v[n-2]-v[0])});
    cout<<x<<"\n"; 
}
int main()
{
    ///*
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    //*/
    jadap;
    int T=1;
    //cin>>T;
    fr(z,0,T){
        solve(z);
    }
    return 0;
}