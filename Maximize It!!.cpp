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
vector<pll> a1(1<<23),a2(1<<23);
vector<pll> v(50);
ll c1=0,c2=0;
ll n,md,k,ans=0;
void rec1(ll p,ll sm,ll c){
    if(c>k)
        return;
    if(p==md){
        a1[c1++]={c,sm};
        return;
    }
    rec1(p+1,sm,c);
    rec1(p+1,sm+v[p].ff,c+v[p].ss);
}
void rec2(ll p,ll sm,ll c){
    if(c>k)
        return;
    if(p==n){
        a2[c2++]={c,sm};
        return;
    }
    rec2(p+1,sm,c);
    rec2(p+1,sm+v[p].ff,c+v[p].ss);
}
bool cmp(pll &a,pll &b){
    if(a.ff==b.ff)
        return a.ss<b.ss;
    return a.ff<b.ff;
}
void solve(ll z){
    cin>>n;
    fr(i,0,n) cin>>v[i].ff;
    fr(i,0,n) cin>>v[i].ss;
    cin>>k;
    md=n>>1;
    rec1(0,0,0);
    rec2(md,0,0);
    sort(a2.begin(),a2.begin()+c2,cmp);    
    sort(a1.begin(),a1.begin()+c1,cmp);

    //For applying upper Bound
    vl fbs(c2);
    fr(i,0,c2)
        fbs[i]=a2[i].ff;

    fr(i,0,c1){
        ll x=a1[i].ff;
        ll y=a1[i].ss;
        if(a2[0].ff>k-x){
            ans=max(ans,y);
        }
        else{
            auto it=upper_bound(fbs.begin(),fbs.end(),k-x);
            it--;
            ans=max(ans,y+a2[it-fbs.begin()].ss);
        }
    }

    fbs.clear();
    fbs.resize(c1);
    
    fr(i,0,c1)
        fbs[i]=a1[i].ff;

    fr(i,0,c2){
        ll x=a2[i].ff;
        ll y=a2[i].ss;
        if(a1[0].ff>k-x){
            ans=max(ans,y);
        }
        else{
            auto it=upper_bound(fbs.begin(),fbs.end(),k-x);
            it--;
            ans=max(ans,y+a1[it-fbs.begin()].ss);
        }
    }

    cout<<ans<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    jadap;
    int T=1;
    //cin>>T;
    fr(z,0,T){
        solve(z);
    }
    return 0;
}