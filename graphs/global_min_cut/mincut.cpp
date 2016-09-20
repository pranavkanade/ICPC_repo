#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<bool> vbl;
typedef vector<vll> vvll;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> plpl;
typedef vector<pl> vpl;
typedef vector<plpl> vplpl;
typedef priority_queue<pl, vpl> maxH;
typedef priority_queue<pl, vpl, greater<pl>> minH;

#define mp(i, j) make_pair((i), (j))
#define pb(i) push_back(i)
#define vec vector

const int INF = 10000000;

pair<int, vll> getMinCut(vvll & weights){
  int N = weights.size();
  vll used(N), cut, best_cut;
  int best_weight = -1;
  for (int phase = N-1; phase >= 0; phase--) {
    vll w = weights[0];
    vll added = used;
    int prev, last = 0;
    for (int i = 0; i < phase; i++) {
      prev = last;
      last = -1;
      for (int j = 1; j < N; j++)
	if (!added[j] && (last == -1 || w[j] > w[last])) last = j;
      if (i == phase-1) {
	cout << " $$$$$$$$ " << prev << " " << last << endl;
	for (int j = 0; j < N; j++)
	  weights[prev][j] += weights[last][j];
	for (int j = 0; j < N; j++)
	  weights[j][prev] = weights[prev][j];
	used[last] = true;
	cut.push_back(last);
	if (best_weight == -1 || w[last] < best_weight) {
	  best_cut = cut;
	  best_weight = w[last];
	}
	cout << endl;
	for(int x = 0; x < N; x ++){
	  for(int y = 0; y < N; y++){
	    cout << weights[x][y] << " ";
	  }
	  cout << endl;
	}
      } else {
	for (int j = 0; j < N; j++)
	  w[j] += weights[last][j];
	added[last] = true;
      }
    }
  }
 return make_pair(best_weight, best_cut);
}

int main(){
  ll N; scanf("%lld", &N);
  ll n, m, a, b, c;
  for(int z = 0; z < N; z++){
    //ll n , m;
    n = 0; m = 0;
    cin >> n >> m;
    vvll weights(n, vll(n));
    
    for(int j = 0; j < m; j++){
      a = 0; b = 0; c = 0;
      cin >> a >> b >> c;
      weights[a-1][b-1] = weights[b-1][a-1] = c;
    }

    pair<int, vll> res = getMinCut(weights);
    cout << "Case #" << z + 1 << ": " << res.first << endl;
  }
}
