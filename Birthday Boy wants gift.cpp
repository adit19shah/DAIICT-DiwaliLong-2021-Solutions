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
ll ncr[5001][5001];
void pre(){
    ncr[0][0]=1;
    fr(i,1,5001)
    {
        ncr[0][i]=0;
        ncr[i][0]=1;
    }
    fr(i,1,5001){
        fr(j,1,5001){
            if(i==j)
                ncr[i][j]=1;
            else if(i<j)
                ncr[i][j]=0;
            else{
                ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
                ncr[i][j]%=mod1;
            }
        }
    }
}
vl zfunc (string s) {
    ll n=s.length();
    vl z(n);
    for (ll i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
void solve(ll z){
    ll n,q; cin>>n>>q;
    vector<char> t(n);
    fr(i,0,n) cin>>t[i];
    string s(t.begin(),t.end());
    vl c(n+1),c2(n+1),a(n+2);
    fr(i,0,n){
        vl zz = zfunc(s.substr(i, n-i));
        fr(i,0,n+1)
            c[i] = 0;

        for(auto x : zz) {
            c[0]++;
            c[x+1]--;
        }

        fr(i,1,n+1){
            c[i] += c[i-1];
            c2[c[i]]++;
        }
        a[1] += n-i;
    }
    fr(i,1,n+1){
        fr(j,1,i+1){
            a[j+1]+=(c2[i]*1ll*ncr[i][j])%mod1;
            a[j+1]%=mod1;
        }
    }

    //answer the queries
    fr(i,0,q){
        ll x;
        cin>>x;
        if(x>n){
            cout<<0<<"\n";
        }
        else{
            cout<<a[x]<<"\n";
        }       
    }
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
    cin>>T;
    pre();
    fr(z,0,T){
        solve(z);
    }
    return 0;
}
