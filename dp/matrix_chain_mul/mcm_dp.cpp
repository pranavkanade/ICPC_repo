#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<lli> arr = {20, 30, 40, 50, 60};

lli mcm(int i, int n){
  vector< vector<lli> > mat(n, vector<lli>(n, 0));
  n--;
  for(int p = n-1; p >= 1; p--){
    for(int q = p+1; q <= n; q++){
      long long int min = INT_MAX;

      for(int j = p; j < q; j++){
	long long int m = mat[p][j] + mat[j+1][q] + (arr[p-1] * arr[j] * arr[q]);

	if(min > m)
	  min = m;
      }

      mat[p][q] = min;
    }
  }

  // for(int p = 0 ; p <= n; p++){
  //   for(int q = 0; q <= n; q++)
  //     cout << mat[p][q] << " ";
  //   cout << endl;
  // }
  return mat[i][n];
}


int main(){

  int n = arr.size();

  cout << mcm(1,n) << endl;
  return 0;
}
