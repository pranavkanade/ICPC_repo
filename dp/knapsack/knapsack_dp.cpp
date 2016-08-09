#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli knapsack_dp(lli n, vector<lli> &val, vector<lli> &wt, llli w){

  vector<lli> tab(n+1, 0);
  vector<lli> W(n+1, 0);
  lli temp = 0;
  lli W = w;
  for(lli i = n; i >= 1; i--){
    for(lli j = 1; j <= n; j++){
      temp = tab[n - j] + val[n-j];
      if(w >= 
    }
  }
}

int main(){
  vector<lli> val = {60, 100, 120};
  vector<lli> wt = {10, 20, 30};

  lli w = 50;
  lli n = val.length();
  cout << knapsack_dp(n, val, wt, w) << endl;
  return 0;
}
