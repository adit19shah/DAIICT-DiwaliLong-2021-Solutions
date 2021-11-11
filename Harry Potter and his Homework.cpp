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
ll sz=sqrt(100000);
bool cmp(pair<pll,ll> &a,pair<pll,ll> &b){
    if(a.ff.ff/sz==b.ff.ff/sz)
        return a.ff.ss<b.ff.ss;
    return a.ff.ff/sz<b.ff.ff/sz; 
}
void solve(ll z){
    ll n,q; cin>>n>>q;
    string s; cin>>s;
    sz=sqrt(n);
    
    //cout<<sz<<" ssk\n";

    vector<pair<pll,ll> > v(q);
    fr(i,0,q){
        ll x,y; cin>>x>>y;
        v[i].ff.ff=x-1;
        v[i].ff.ss=y-1;
        v[i].ss=i;
    }

    //Mo's Algorithm
    sort(all(v),cmp);
    ll a=0;
    vl lc(n),rc(n);
    lc[0]=rc[n-1]=1;
    ll x=1;
    fr(i,1,n){
        if(s[i]==s[i-1])
            x=1;
        else
            x++;
        lc[i]=x;
    }
    x=1;
    for(ll i=n-2;i>=0;i--){
        if(s[i]==s[i+1])
            x=1;
        else
            x++;
        rc[i]=x;
    }

    vl ans(q);

    ll ml=0,mr=-1;
    ll l,r;
    fr(i,0,q){
        l=v[i].ff.ff;
        r=v[i].ff.ss;
        //cout<<l<<" "<<r<<" "<<ml<<" "<<mr<<"\n";
        while(mr<r){
            mr++;
            ll w=min(lc[mr],mr-ml+1);
            a+=w;
        }
        //cout<<a<<"\n";
        while(mr>r){
            ll w=min(lc[mr],mr-ml+1);
            a-=w;
            mr--;
        }
        //cout<<a<<"\n";
        while(ml>l){
            ml--;
            ll w=min(rc[ml],mr-ml+1);
            a+=w;
        }
        //cout<<a<<"\n";
        while(ml<l){
            ll w=min(rc[ml],mr-ml+1);
            a-=w;
            ml++;
        }
       // cout<<a<<"\n";
        ans[v[i].ss]=a;
    }

    fr(i,0,q)
        cout<<ans[i]<<"\n";

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