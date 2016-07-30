#include <bits/stdc++.h>

using namespace std;

#define ulli long long int
// #define ulli unsigned long long int
// the -ve nos were needed so use above whenever required else don't
ulli table(vector<ulli> s, vector< vector<ulli> > tab, ulli m, ulli n){
  for(ulli i = 1; i <= m; i++){
    tab[i][0] = 1;
  }

  for(ulli i = 1; i <= m; i++){
    for(ulli j = 1; j <= n; j++){
      if(j - s[i-1] < 0)
	tab[i][j] = tab[i-1][j];
      else
	tab[i][j] = tab[i-1][j] + tab[i][j - s[i-1]];
    }
  }

  return tab[m][n];
}

int main(){
  vector<ulli> s = {1, 2, 3};
  ulli m = s.size();

  ulli n = 150;
  
  vector< vector<ulli> > tab(m+1, vector<ulli> (n+1, 0)); 

  cout << table(s, tab, m, n) << endl; 
  
  return 0;
}
