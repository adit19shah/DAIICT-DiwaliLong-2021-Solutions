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
#define imx 1e15
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
#define eps 0.00000000001   //Epsilon value below which approximate floating type number as 0
#define mod1 1000000007
#define mod2 998244353
#define jadap ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ld dis(pll s,pll d){
    ll a=s.ff-d.ff;
    ll b=s.ss-d.ss;
    return sqrt((ld)(a*a+b*b));
}
void solve(ll z){
    ll n,hp; cin>>n>>hp;
    ll a,b,p,q; cin>>a>>b>>p>>q;
    vector<pair<pll,ll> > v(n+2);
    v[0]={{a,b},0};
    v[n+1]={{p,q},0};
    fr(i,1,n+1){
        cin>>v[i].ff.ff>>v[i].ff.ss>>v[i].ss;
    }

    //Construct adjacency matrix
    vector<vector<ld> > adj(n+2,vector<ld> (n+2));
    fr(i,0,n+2){
        fr(j,i,n+2){
            adj[i][j]=adj[j][i]=(ld)max((ld)0,dis(v[i].ff,v[j].ff)-(ld)(v[i].ss+v[j].ss));
            //cout<<i<<" "<<j<<" "<<adj[i][j]<<"\n";
        }
    }

    //Dijkstra from v[0] to v[n+1]
    vector<bool> vis(n+2);
    vector<ld> cost(n+2,(ld)imx);
    cost[0]=0;
    priority_queue <pair<ld,ll>,vector<pair<ld,ll> >, greater<pair<ld,ll> > > pq; //pair of {cost,index}
    pq.push({(ld)0,0});
    while(!pq.empty()){
        pll x=pq.top();
        pq.pop();
        if(!vis[x.ss]){
            vis[x.ss]=true;
            fr(j,0,n+2){
                if(!vis[j]){
                    if(cost[x.ss]+adj[x.ss][j]<cost[j])
                    {
                        cost[j]=cost[x.ss]+adj[x.ss][j];
                        pq.push({cost[j],j});
                    }
                }
            }
        }
    }

    //cout<<cost[n+1]<<" ";

    if((ld)cost[n+1]<(ld)hp){
        cout<<"YES\n";
        cout<<(ld)hp-cost[n+1]; 
    }
    else{
        cout<<"NO\n";
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
    //cin>>T;
    cout << fixed;
    cout << setprecision(15);
    fr(z,0,T){
        solve(z);
    }
    return 0;
}