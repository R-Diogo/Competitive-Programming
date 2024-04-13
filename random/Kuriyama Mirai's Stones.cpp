#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 200 + 10

using namespace std;

// Using Sqr Decomposition. Its faster (and simplier) to use BIT.

void solve(){
    ll n, q, x, l, r, ans; cin>>n;
    ll len = (ll) sqrt(n + .0) + 1;
    vector<ll> v(n), u(n), sqr_v(len, 0), sqr_u(len, 0);
    rep(n){
        cin>>u[i];
        sqr_v[i / len] += u[i];
    }
    v = u;
    sort(u.begin(), u.end());
    rep(n) sqr_u[i / len] += u[i]; 

    cin>>q;
    rep(q){
        cin>>x>>l>>r;
        l--; r--; //we are considering [0 - n-1]
        ll cl = l / len, cr = r / len;
        ans = 0;
        if(x == 1){
            if(cl == cr) for(ll i = l; i<= r; i++) ans += v[i];
            else{
                for(ll i = l, end = (cl+1)*len; i<end; i++) ans += v[i];
                for(ll i = cl+1; i<cr; i++) ans += sqr_v[i];
                for(ll i = cr*len; i<=r; i++) ans += v[i];
            }
        }
        else{
            if(cl == cr) for(ll i = l; i<= r; i++) ans += u[i];
            else{
                for(ll i = l, end = (cl+1)*len; i<end; i++) ans += u[i];
                for(ll i = cl+1; i<cr; i++) ans += sqr_u[i];
                for(ll i = cr*len; i<=r; i++) ans += u[i];
            }
        }

        cout<<ans<<'\n';
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
