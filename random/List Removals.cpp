#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 200001

using namespace std;

// Using Segment Tree.

ll st[MAXN<<2], v[MAXN], n;

void build(ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr) st[pos] = 1;
    else{
        ll tm = (tl + tr)>>1;
        build(pos<<1, tl, tm);
        build((pos<<1)+1, tm+1, tr);
        st[pos] = st[pos<<1] + st[(pos<<1)+1];
    }
}

void update(ll a, ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        st[pos] = 0;
    }
    else{
        ll tm = (tl + tr)>>1;
        if(a > tm) update(a, (pos<<1)+1, tm+1, tr);
        else update(a, pos<<1, tl, tm);
        st[pos] = st[pos<<1] + st[(pos<<1)+1];
    }
}

ll find_kth(ll k, ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        update(tl);
        return tl;
    }
    else{
        ll tm = (tl + tr)>>1;
        if(k > st[pos<<1]) return find_kth(k-st[pos<<1], (pos<<1)+1, tm+1, tr);
        else return find_kth(k, pos<<1, tl, tm);
    }
}

void solve(){
    ll x, aux; cin>>n;
    build();
    rep(n){
        cin>>v[i+1];
    }
    
    rep(n){
        cin>>x;
        cout<<v[find_kth(x)]<<' ';
    }
    cout<<'\n';
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
