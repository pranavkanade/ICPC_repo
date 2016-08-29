#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector< pair< pair <ll, ll>, string> > tab;

ll solve(ll n, ll k, ll s, ll e){
  


  //return 0;
}

int main(){
  ll n, k;
  string sign;
  ll ki, kj;
  cin >> n >> k;
  pair<pair <ll, ll>, string> stmt;
  pair<ll, ll> indx;
  // cout << n1 << endl;
  for(ll i = 0; i < k; i++){
    cin >> ki >> sign >> kj;
    indx = make_pair(ki, kj);
    stmt = make_pair(indx, sign);
    tab.push_back(stmt);
  }

  cout << solve(n, k, 0, 2*n-1) << endl;
}
