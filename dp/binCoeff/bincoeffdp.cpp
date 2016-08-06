#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


// following function has n^2 complexity and n^2 space complexity

lli bincoeffdp(lli n, lli k){
  vector< vector<lli> > mat(n+1, vector<lli>(k+1, 0));

  for(lli i = 0; i <= n; i++){
    for(lli j = 0; j <= i && j <= k ; j++){
      if(j == 0)
	mat[i][j] = 1;
      else if(j == i)
	mat[i][j] = 1;
      else {
	mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
      }
      //cout << "( " << i << ", " << j << ")" << endl;
    }
  }
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= k; j++){
  //     cout << mat[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return mat[n][k];
}

int main(){
  lli n;
  lli k;
  cout << "this is nCr finding problem" << endl;
  cout << "n : ";
  cin >> n;
  cout << "k : ";
  cin >> k;
  cout << bincoeffdp(n , k) << endl;
}
