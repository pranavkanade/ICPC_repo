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
ll recSearch(int mLeft, int indx){
  if(mLeft <= 0 && indx < c){
    return -99999;
  }
  if(memo[mLeft][indx] != -999999)
    return memo[mLeft][indx];
  else if(indx == c-1){
    ll min = 99999;
    ll j;
    for(int i = 0; i < inp[indx].size(); i++){
      if(min > mLeft-inp[indx][i] && mLeft-inp[indx][i] >= 0){
	min = mLeft-inp[indx][i];
	j = i;
	memo[mLeft][inp[indx][i]] = min;
      }
      else
	memo[mLeft][inp[indx][i]] = -99999;
    }
    if(min < 99999)
      return inp[indx][j];
    else
      return -99999;
  }
  else{
    ll max = -99999;
    ll j;
    ll test;
    for(int i = 0; i < inp[indx].size(); i++){
      if(memo[mLeft][i] != -999999)
	test = memo[mLeft][inp[indx][i]];
      else
	test = recSearch(mLeft-inp[indx][i], indx+1);
      if(test >= max){
	max = test;
	j = i;
	memo[mLeft][inp[indx][i]] = test;
      }else
	memo[mLeft][inp[indx][i]] = -99999;
    }

    return max + inp[indx][j];
  }
}

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
