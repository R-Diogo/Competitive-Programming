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

ll v[MAXN], st[4*MAXN];

void build(ll pos, ll tl, ll tr){
    if(tl == tr){
        st[pos] = v[tl];
        return;
    }

    ll tm = (tl + tr)/2;
    build(2*pos, tl, tm);
    build(2*pos+1, tm+1, tr);
    st[pos] = max(st[2*pos], st[2*pos+1]);
}

ll get(ll pos, ll tl, ll tr, ll val){
    if(tl == tr) return tl;

    ll tm = (tl + tr)/2;
    if(st[2*pos] >= val) return get(2*pos, tl, tm, val);
    else return get(2*pos+1, tm+1, tr, val);
}

void update(ll pos, ll tl, ll tr, ll j){
    if(tl == tr){
        st[pos] = v[j];
        return;
    }

    ll tm = (tl + tr)/2;
    if(j > tm) update(2*pos+1, tm+1, tr, j);
    else update(2*pos, tl, tm, j);
    st[pos] = max(st[2*pos], st[2*pos+1]);
}

void solve(){
    ll n, m, x; cin>>n>>m;
    rep(n) cin>>v[i+1];

    build(1, 1, n);

    rep(m){
        cin>>x;
        if(st[1] >= x){
            ll aux = get(1, 1, n, x);
            cout<<aux<<' ';
            v[aux] -= x;
            update(1, 1, n, aux);
        }
        else cout<<"0 ";
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
