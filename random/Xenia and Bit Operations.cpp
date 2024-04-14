#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 1<<18

using namespace std;

//Using Segment Tree

ll n, vec[MAXN];
pll st[4*MAXN];

void build(ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        st[pos] = make_pair(vec[tl], 1);
    }
    else{
        ll tm = (tl + tr)>>1;
        build(pos<<1, tl, tm);
        build((pos<<1)+1, tm+1, tr);
        if(st[pos<<1].second){
            st[pos] = make_pair((st[pos<<1].first)|(st[(pos<<1)+1].first), 0);
        }
        else{
            st[pos] = make_pair((st[pos<<1].first)^(st[(pos<<1)+1].first), 1); 
        }
    }
}

void update(ll p, ll b, ll pos = 1, ll tl = 1, ll tr = n){
    if(tl == tr){
        st[pos].first = b;
    } 
    else{
        ll tm = (tl + tr)>>1;
        if(p > tm) update(p, b, (pos<<1)+1, tm+1, tr);
        else update(p, b, pos<<1, tl, tm);

        if(st[pos<<1].second){
            st[pos].first = (st[pos<<1].first)|(st[(pos<<1)+1].first);
        }
        else{
            st[pos].first = (st[pos<<1].first)^(st[(pos<<1)+1].first); 
        }
    }
}

void solve(){
    ll q, p, b; cin>>n>>q;
    n = 1<<n;
    rep(n) cin>>vec[i+1];
    build();
    rep(q){
        cin>>p>>b;
        update(p, b);
        cout<<st[1].first<<'\n';
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