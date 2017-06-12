#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define vec vector

typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;

ll nStations, nPosts;

int main() {
  cin >> nStations >> nPosts;

  vll lStations(nStations);
  vvll dpTab(nStations + 1, vll(nPosts + 1 , 0));
  for(ll i = 0; i < nStations; i++){
    cin >> lStations[i];
  }

  for(ll i = 0; i <= nStations; i++){
    for(ll j = 0; j <= nPosts; j++){

      }
    }
  }
  

  return 0;
}
