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

// Using Mo's Algorithm.

ll block_size;
int mp[1000001];

bool cmp(tuple<ll, ll, ll> t1, tuple<ll, ll, ll> t2){
    pair<ll, ll> p1, p2;
    p1.first = get<0> (t1); p1.second = get<1> (t1);
    p2.first = get<0> (t2); p2.second = get<1> (t2);
    if(p1.first / block_size != p2.first / block_size){
        return p1 < p2;
    }
    return ((p1.first / block_size) & 1)? (p1.second < p2.second) : (p1.second > p2.second); 
}

void solve(){
    ll n, ans = 0; cin>>n;
    block_size = (ll) sqrt(n + .0) + 1;
    vector<ll> v(n);
    rep(n){
        cin>>v[i];
    }

    ll q; cin>>q;
    vector<tuple<ll, ll, ll>> query(q);
    vector<ll> fin(q);
    rep(q){
        ll x, y;
        cin>>x>>y;
        x--; y--;
        query[i] = {x, y, i};
    }
    sort(query.begin(), query.end(), cmp);

    ll i = 0, j = -1;
    for(auto [l, r, place] : query){
        while(i > l){
            i--;
            if(mp[v[i]] == 0) ans++;
            mp[v[i]]++;
        }
        while(j < r){
            j++;
            if(mp[v[j]] == 0) ans++;
            mp[v[j]]++;
        }
        while(i < l){
            mp[v[i]]--;
            if(mp[v[i]] == 0) ans--;
            i++;
        }
        while(j > r){
            mp[v[j]]--;
            if(mp[v[j]] == 0) ans--;
            j--;
        }
        fin[place] = ans;
    }
    rep(fin.size()) cout<<fin[i]<<'\n';
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
