/*
Author: taha-r
Bismillah
*/

#include <functional>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define endll '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)

inline void open(const char *fin, const char *fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &arr) {
	os << "[";
	for (T &x : arr) {
		os << x << " ";
	}
	os << "]";
	return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &x) {
	os << "(" << x.first << ", " << x.second << ")";
	return os;
}


void solve(int num_tc)
{
    int X, N; cin >> X >> N;
    multiset<int> lengths{};
    set<pair<int, int>> segments{};

    lengths.insert(X);
    segments.insert({0, X-1});

    for(int i = 0; i < N; i++)
    {
        int p; cin >> p;
        auto seg = --segments.upper_bound({p, 0});
        int oldLen = seg->second - seg->first + 1;
        lengths.erase(lengths.find(oldLen));

        pair<int, int> newLower = {seg->first, p-1};
        pair<int, int> newUpper = {p, seg->second};

        lengths.insert(newLower.second - newLower.first + 1);
        lengths.insert(newUpper.second - newUpper.first + 1);
        
        segments.erase(seg);
        segments.insert(newLower);
        segments.insert(newUpper);

        cout << *--lengths.end() << " ";
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}
