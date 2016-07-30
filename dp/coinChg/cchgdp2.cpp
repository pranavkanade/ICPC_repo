#include <bits/stdc++.h>

using namespace std;

#define ulli long long int

ulli table(vector<ulli> s, vector<ulli> tab, ulli m, ulli n){

  tab[0] = 1;
  for(ulli i = 1; i <= m; i++){
    for(ulli j = 1; j <= n; j++){
      if(j - s[i-1] < 0)
	tab[j] = tab[j];
      else
	tab[j] = tab[j] + tab[j - s[i-1]];
    }
  }

  return tab[n];
}

int main(){
  vector<ulli> s = {1, 2, 3};
  ulli m = s.size();

  ulli n = 15;
  
  vector<ulli> tab(n+1, 0); 

  cout << table(s, tab, m, n) << endl; 
  
  return 0;
}
