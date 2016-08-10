#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define vec vector

lli max(lli a, lli b){
  return a > b ? a : b;
}

lli egg_dp(lli n, lli h){
  vec<vec<lli>> tab(n+1, vec<lli>(h+1, 0));
  // cout << " h :  " << h << endl;
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= h; j++){
  //     cout << tab[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  
  for(lli i = 1; i <= n; i++){
    for(lli j = 1; j <= h; j++){
      // cout << i << endl;
      if(i == 1){
  	tab[i][j] = j;
      }
      else if(j == 1)
      	tab[i][j] = 1;
      else{
      	lli min = LONG_MAX;
      	lli temp = 0;
      	for(lli x = 1; x <= j; x++){
      	  temp = max(tab[i-1][x-1], tab[i][j - x]);
      	  if(min > temp)
      	    min = temp;
      	}
      	tab[i][j] = 1 + min;
      }
    }

    // for(int i = 0; i <= n; i++){
    //   for(int j = 0; j <= h; j++){
    // 	cout << tab[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;  
  }

  
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= h; j++){
  //     cout << tab[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return tab[n][h];
}

int main (){
  lli n = 4;
  lli h = 100;

  cout << egg_dp(n, h) << endl;
  return 0;
}
