// working of the substr() function must be noted;

#include <bits/stdc++.h>

using namespace std;
unsigned long int min(unsigned long int x, unsigned long int y, unsigned long int z)
{
    return min(min(x, y), z);
}

unsigned long int editdp(string str1, string str2, unsigned int m, unsigned int n){

  unsigned long int tab[m+1][n+1];
  
  for(unsigned long int i = 0; i <= m; i++){
    for (unsigned long int j = 0; j <= n; j++){
      if(i == 0) {
  	tab[i][j] = j;
      }else if(j == 0) {
  	tab[i][j] = i;
      }else if(str1[i-1] == str2[j-1]){
  	tab[i][j] = tab[i-1][j-1];
      }else{
  	tab[i][j] = 1 + min(tab[i][j-1], tab[i-1][j], tab[i-1][j-1]);
      }

    }
  }
     return tab[m][n];
}


int main(){
  string str1;
  string str2;
  unsigned long int m, n;
  long int t = 0;
  cin >> t;
  while(t != 0){
    cin >> m >> n;
    cin >> str1 >> str2;
  
    unsigned long int ans = editdp(str1, str2, m, n);
    cout << ans << endl;
    t--;
    m = 0; n = 0; 
  }
  
  return 0;
}
