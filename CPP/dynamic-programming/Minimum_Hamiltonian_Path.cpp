#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=(ll)4e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<vector<ll>> adj(n,vector<ll>(n,INF));
    for(int i=0;i<m;++i) {
        int u,v;
        ll wt;
        cin>>u>>v>>wt;
        --u;--v;
        adj[u][v]=min(adj[u][v],wt);
    }
    
    int ALL=1<<n;
    vector<vector<ll>> dp(ALL,vector<ll>(n,INF));
    
    for(int v=0;v<n;++v) dp[1<<v][v]=0;
    
    for(int mask=1;mask<ALL;++mask) {
        for(int x=0;x<n;++x) {
            if(!(mask&(1<<x))) continue;
            ll cur=dp[mask][x];
            if(cur==INF) continue;
            int z=(~mask)&(ALL-1);
            for(int y=0;y<n;++y) {
                if(!(z&(1<<y))) continue;
                if(adj[x][y]==INF) continue;
                int nmask=mask|(1<<y);
                ll cand=cur+adj[x][y];
                if(cand<dp[nmask][y]) dp[nmask][y]=cand;
            }
        }
    }
    
    ll ans=INF;
    int finalMask=ALL-1;
    for(int v=0;v<n;++v) {
        ans=min(ans,dp[finalMask][v]);
    }
    if(ans>=INF/2) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    
    return 0;
}
