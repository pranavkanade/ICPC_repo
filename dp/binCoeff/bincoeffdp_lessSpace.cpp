#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli bincoeffdp2(lli n, lli k){
  vector<lli> mat(k+1, 0);
  mat[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = min((float)i,(float)k); j > 0; j--){
      mat[j] = mat[j-1] + mat[j];
    }
  }

  return mat[k];
}

int main(){
  lli n;
  lli k;
  cout << "this is nCr finding problem" << endl;
  cout << "n : ";
  cin >> n;
  cout << "k : ";
  cin >> k;
  cout << bincoeffdp2(n , k) << endl;
}
