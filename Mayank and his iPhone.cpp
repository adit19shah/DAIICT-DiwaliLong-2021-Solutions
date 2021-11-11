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
void yno(bool ok)
{
    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
bool isok(pll a){
    if(a.ff==4 && a.ss==2)
        return tr;
    return a.ff<=3 && a.ss<=3 && a.ff>=1 && a.ss>=1;
}
pll pdf(pll a,pll b){
    return {b.ff-a.ff,b.ss-a.ss};
}
void solve(ll z){
    ll n;
    string s;
    cin>>n>>s;
    unordered_map<char,pll> mp;
    mp['1']={1,1};
    mp['2']={1,2};
    mp['3']={1,3};
    mp['4']={2,1};
    mp['5']={2,2};
    mp['6']={2,3};
    mp['7']={3,1};
    mp['8']={3,2};
    mp['9']={3,3};
    mp['0']={4,2};
    bool b;
    bl ok=tr;
    fr(i,0,10){
        pll x=pdf(mp[s[0]],mp[i+'0']);
        b=tr;
        fr(j,0,n){
            b=isok({mp[s[j]].ff+x.ff,mp[s[j]].ss+x.ss});
            if(!b)
                break;
        }
        if(i+'0'!=s[0] && b)
        {
            ok=fl;
            break;
        }
    }  
    yno(ok);
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
    fr(z,0,T){
        solve(z);
    }
    return 0;
}