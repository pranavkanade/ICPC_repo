#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;

lli max(lli a, lli b){
  return a > b ? a : b;
}

lli rec(lli n, lli w, vector<lli> &wt, vector<lli> &val){
  f(n < 0)
    return 0;
  else if(w < wt[n])
    return rec(n-1, w, wt,val);
  // if(w <= 0)   the above condition is rather correct in the essence that
  //   return 0;  the element which has weight greater than the knapsack is 
  //              not included in the optimal solution.
  else{
    return max(val[n] + rec(n-1,w - wt[n], wt, val), rec(n-1, w, wt, val));
  }
}

int main(){
  lli n;
  cout << " n : ";
  cin >> n;

  lli w;
  cout << " w: ";
  cin >> w;
  
  vector<lli> wt(n);
  vector<lli> val(n);

  for(lli i = 0; i < n; i++){
    cin >> val[i] >> wt[i];
  }

  lli total = rec(n-1, w, wt, val);

  cout << total << endl;
  return 0;
}
