#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 200010

using namespace std;

// Using Segment Tree.

ll st[4*MAXN], v[MAXN], n;

void build(ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr) st[pos] = v[tl];
    else{
        ll tm = (tl + tr)>>1;
        build(pos<<1, tl, tm);
        build((pos<<1)+1, tm+1, tr);
    }
}

void update(ll l, ll r, ll val, ll pos = 1, ll tl = 1, ll tr = n){
    if(l > r) return;
    if(l == tl && r == tr) st[pos] += val;
    else{
        ll tm = (tl + tr)>>1;
        update(l, min(r, tm), val, pos<<1, tl, tm);
        update(max(l, tm+1), r, val, (pos<<1)+1, tm+1, tr);
    }
}

ll get(ll a, ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr) return st[pos];
    else{
        ll tm = (tl + tr)>>1;
        if(a > tm) return st[pos] + get(a, (pos<<1)+1, tm+1, tr);
        else return st[pos] + get(a, pos<<1, tl, tm);
    }
}

void solve(){
    ll q, c, a, b, x; cin>>n>>q;
    rep(n) cin>>v[i+1];

    build();

    rep(q){
        cin>>c;
        if(c == 1){
            cin>>a>>b>>x;
            update(a, b, x);
        }
        else{
            cin>>x;
            cout<<get(x)<<'\n';
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
