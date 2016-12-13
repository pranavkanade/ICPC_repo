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

#define vec vector

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))

// unordered set;
// unordered map;

vvll inp;
ll m, c;
ll recSearch(int mLeft, int indx){
  if(mLeft <= 0 && indx < c){
    return -99999;
  }
  if(indx == c-1){
    ll min = 99999;
    ll j;
    for(int i = 0; i < inp[indx].size(); i++){
      if(min > mLeft-inp[indx][i] && mLeft-inp[indx][i] >= 0){
	min = mLeft-inp[indx][i];
	j = i;
      }
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
      test = recSearch(mLeft-inp[indx][i], indx+1);
      if(test >= max){
	max = test;
	j = i;
      }
    }

    return max + inp[indx][j];
  }
}

int main(){
 
  cin >> m >> c;
 
  for(int i = 0; i < c; i++){
    int tempSize;
    cin >> tempSize;
    inp.pb(vll(tempSize));
    for(int j = 0; j < tempSize; j++){
      int p;
      cin >> p;
      inp[i][j] = p;
    }
  }

  ll output = recSearch(m, 0);
  if(output < 0){
    cout << "not possible" << endl;
  }
  else
    cout << output << endl;
}
