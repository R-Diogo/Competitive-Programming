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
        st[pos] = st[pos<<1] + st[(pos<<1)+1];
    }
}

void update(ll a, ll val, ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        st[pos] = val;
        v[a] = val;
    }
    else{
        ll tm = (tl + tr)>>1;
        if(a > tm) update(a, val, (pos<<1)+1, tm+1, tr);
        else update(a, val, pos<<1, tl, tm);
        st[pos] = st[pos<<1] + st[(pos<<1)+1];
    }
}

ll get(ll l, ll r, ll pos = 1, ll tl = 1, ll tr = n){
    if(l > r) return 0;
    if(l == tl && r == tr) return st[pos];

    ll tm = (tl + tr)>>1;
    return get(l, min(r, tm), pos<<1, tl, tm) + get(max(l , tm+1), r, (pos<<1)+1, tm+1, tr);
}

void solve(){
    ll q, c, a, b; cin>>n>>q;
    rep(n) cin>>v[i+1];

    build();

    rep(q){
        cin>>c>>a>>b;
        if(c == 1){
            update(a, b);
        }
        else{
            cout<<get(a, b)<<'\n';
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