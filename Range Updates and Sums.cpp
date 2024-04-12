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

// Using Lazy Segment Tree.

ll v[MAXN], st[4*MAXN], marked_sum[4*MAXN], marked_upd[4*MAXN], n;

void build(ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        st[pos] = v[tl];
        return;
    }

    ll tm = (tl + tr)/2;
    build(2*pos, tl, tm); build(2*pos+1, tm+1, tr);
    st[pos] = st[2*pos] + st[2*pos+1];
}

void push(ll pos, ll tl, ll tr){
    ll l = 2*pos, r = 2*pos+1, tm = (tl + tr)/2;
    if(marked_upd[pos] != 0){
        marked_upd[l] = marked_upd[pos];
        marked_upd[r] = marked_upd[pos];
        marked_sum[l] = 0;
        marked_sum[r] = 0;
        st[l] = (tm-tl+1)*marked_upd[pos];
        st[r] = (tr-tm)*marked_upd[pos];
        marked_upd[pos] = 0;
    }
    if(marked_sum[pos] != 0){
        marked_sum[l] += marked_sum[pos];
        marked_sum[r] += marked_sum[pos];
        st[l] += (tm-tl+1)*marked_sum[pos];
        st[r] += (tr-tm)*marked_sum[pos];
        marked_sum[pos] = 0;
    } 
}

void update_sum(ll l, ll r, ll val, ll pos = 1, ll tl = 1, ll tr = n){
    if(l > r) return;
    if(l == tl && r == tr){
        marked_sum[pos] += val;
        st[pos] += (r-l+1)*val;
    }
    else{
        push(pos, tl, tr);
        ll tm = (tl + tr)/2;
        update_sum(l, min(r, tm), val, 2*pos, tl, tm);
        update_sum(max(l, tm+1), r, val, 2*pos+1, tm+1, tr);
        st[pos] = st[2*pos] + st[2*pos+1];
    }
}

void update_upd(ll l, ll r, ll val, ll pos = 1, ll tl = 1, ll tr = n){
    if(l > r) return;
    if(l == tl && r == tr){
        marked_upd[pos] = val;
        marked_sum[pos] = 0;
        st[pos] = (r-l+1)*val;
    }
    else{
        push(pos, tl, tr);
        ll tm = (tl + tr)/2;
        update_upd(l, min(r, tm), val, 2*pos, tl, tm);
        update_upd(max(l, tm+1), r, val, 2*pos+1, tm+1, tr);
        st[pos] = st[2*pos] + st[2*pos+1];
    }
}

ll get(ll l, ll r, ll pos = 1, ll tl = 1, ll tr = n){
    if(l > r) return 0;
    if(tl == l && tr == r) return st[pos];

    push(pos, tl, tr);
    ll tm = (tl + tr)/2;
    return get(l, min(r, tm), 2*pos, tl, tm) + get(max(l, tm+1), r, 2*pos+1, tm+1, tr);
}

void solve(){
    ll q, c, a, b, x; cin>>n>>q;
    rep(n) cin>>v[i+1];

    build();

    rep(q){
        cin>>c>>a>>b;
        if(c == 1){
            cin>>x;
            update_sum(a, b, x);
        }
        else if(c == 2){
            cin>>x;
            update_upd(a, b, x);
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