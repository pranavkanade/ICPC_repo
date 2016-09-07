#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
#define loop(i, j, k) for(ll i = j; i < k; i++)
const int N = 100;

ll n, k;
ll a[N], b[N];
string sign[N];
ll dpTab[N][N];

enum{
  OLD,
  CURR,
  NEW
};
ll F, S, L, R;
ll n2;

bool compare(int lf, int rg, string st){
  if(st == "=")
    return lf == rg;
  else if(st == ">")
    return lf > rg;
  else if(st == "<")
    return lf < rg;
  else if(st == ">=")
    return lf >= rg;
  else if(st == "<=")
    return lf <= rg;
  else
    return false;
}

int get_type(int aa){
  if(aa < L || aa > R)
    return OLD;
  if(aa == F || aa == S)
    return CURR;
  else
    return NEW;
}

bool is_good(ll l, ll r, ll f, ll s){
  L = l; R = r;
  F = f; S = s;
  //int i;
  loop(i, 0, k){
    int lf = get_type(a[i]);
    int rg = get_type(b[i]);

    if(lf != CURR && rg != CURR){
      continue;
    }

    if(!compare(lf, rg, sign[i])){
      return false;
    }
  }

  return true;
}

ll solve(ll l, ll r){
  ll &res = dpTab[l][r];

  if(res != -1)
    return res;

  res = 0;

  if(l+1 == r){
    if(is_good(l,r,l,r))
      res++;
  } else {
    if(is_good(l,r,l,l+1))
      res += solve(l+2, r);
    if(is_good(l, r, l, r))
       res += solve(l+1, r-1);
    if(is_good(l, r, r-1, r))
      res += solve(l, r-2);
  }
  return res;
}

int main(){
 cin >> n >> k;

 n2 = 2 * n;
 memset(dpTab, -1, sizeof(dpTab));

 loop(i, 0, k){
   cin >> a[i] >> sign[i] >> b[i];
   a[i]--;
   b[i]--;
 }

 cout << solve(0, n2 -1);
 return 0;
}
