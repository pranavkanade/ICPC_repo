#include <bits/stdc++.h>
using namespace std;

#define ulli unsigned long long int
#define lli long long int
#define li long int
#define R 3
#define C 3

ulli tab[R+1][C+1];

ulli minPath(ulli x, ulli z, ulli cost[R][C]){
  
  for(ulli p = 0; p <= x; p++){
    for(ulli q = 0; q <= z; q++){
      if(p == 0 || q == 0){
	tab[p][q] = 0;
      }else if(p == 1 && q == 1)
	tab[p][q] = cost[p-1][q-1];
      else if(p == 1)
	tab[p][q] = tab[p][q-1] + cost[p-1][q-1];
      else if(q == 1)
	tab[p][q] = tab[p-1][q] + cost[p-1][q-1];
      else{
	tab[p][q] = cost[p-1][q-1] + min(min(tab[p-1][q-1], tab[p-1][q]), tab[p][q-1]);
      }
    }
  }
  return tab[x][z];
  
}

int main(){
  ulli t = 0;
  cin >> t;
  ulli cost[R][C] = { {1, 2, 3},
		      {4, 8, 2},
		      {1, 5, 3} };
  ulli i, j;
  while(t != 0){
    cin >> i >> j;
    i++; j++;
    cout << minPath(i, j, cost) << endl;
    t--;
  }
  return 0;
}
