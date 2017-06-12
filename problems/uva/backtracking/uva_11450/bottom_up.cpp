#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vll, greater<>> minHeap;
typedef priority_queue<ll, vll> maxHeap;
typedef unordered_map<ll, ll> hashTab;


#define vec vector

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))

// unordered set;
// unordered map;
vvll memo;
vvll inp;
ll m, c;
ll maxSize;

int main(){
 
  cin >> m >> c;
  ll mx = 0;
  for(int i = 0; i < c; i++){
    int tempSize;
    cin >> tempSize;
    if(mx < tempSize)
      mx = tempSize;
    inp.pb(vll(tempSize));
    for(int j = 0; j < tempSize; j++){
      int p;
      cin >> p;
      inp[i][j] = p;
    }
  }

  for(int i = 0; i < c; i++){
    for(int j = 0; j < 
  }
  for(int i = 0; i <= m; i++){
    memo.pb(vll(mx+1, -999999));
  }
  cout << " P " << endl;
  ll output = recSearch(m, 0);
  if(output < 0){
    cout << "not possible" << endl;
  }
  else
    cout << output << endl;
}
