#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 1010

using namespace std;

// Using Matrix Sum (DP).

ll grid[MAXN][MAXN];

void solve(){
    ll n, q, a, b, x, y; cin>>n>>q;
    char c;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            cin>>c;
            if(c == '*') grid[i][j] = 1;
        }
    }

    for(ll i = 1; i<=n; i++){
        ll aux = 0;
        for(ll j = 1; j<=n; j++){
            aux += grid[i][j];
            if(i == 1){
                grid[i][j] = aux;
            }
            else{
                grid[i][j] = grid[i-1][j] + aux;
            }
        }
    }

    rep(q){
        cin>>a>>b>>x>>y;
        if(a > x) swap(a, x);
        if(b > y) swap(b, y);

        cout<<grid[x][y] - grid[a-1][y] - grid[x][b-1] + grid[a-1][b-1]<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}