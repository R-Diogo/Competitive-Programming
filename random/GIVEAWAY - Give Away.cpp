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

// Using Sqr Decomposition. O(q*sqrt(n)*log(n))

void solve(){
    ll n; cin>>n;
    const ll len = (ll) sqrt(n + .0) + 1;
    vector<ll> v(n), sqr_v[len];
    rep(n){
        cin>>v[i];
        sqr_v[i / len].push_back(v[i]);
    }
    rep(len) sort(sqr_v[i].begin(), sqr_v[i].end());

    ll q, x, a, b, c, ans; cin>>q;
    rep(q){
        ans = 0;
        cin>>x;
        if(!x){
            cin>>a>>b>>c;
            a--; b--;
            ll cl = a / len, cr = b / len;
            if(cl == cr){
                for(ll i = a; i<=b; i++){
                    if(v[i] >= c) ans++;
                }
            }
            else{
                for(ll i = a, end = (cl+1)*len; i<end; i++) if(v[i] >= c) ans++;
                for(ll i = cl+1; i<cr; i++){
                    ll aux = lower_bound(sqr_v[i].begin(), sqr_v[i].end(), c) - sqr_v[i].begin();
                    ans += (len - aux);
                }
                for(ll i = cr*len; i<=b; i++) if(v[i] >= c) ans++;
            }
            cout<<ans<<'\n';
        }
        else{
            cin>>a>>b;
            a--;
            ll cl = a / len;
            ll aux = upper_bound(sqr_v[cl].begin(), sqr_v[cl].end(), v[a]) - sqr_v[cl].begin() - 1;
            v[a] = b;
            sqr_v[cl][aux] = b;
            sort(sqr_v[cl].begin(), sqr_v[cl].end());
        }
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
