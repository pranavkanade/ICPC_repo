#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli bincoeff(lli n, lli k){
  if(k == 0)
    return 1;
  else if(k == n)
    return 1;
  else{
    return (bincoeff(n-1, k-1) + bincoeff(n-1, k));
  }
}


int main(){
  lli n;
  lli k;
  cout << "this is nCr finding problem" << endl;
  cout << "n : ";
  cin >> n;
  cout << "k : ";
  cin >> k;
  cout << bincoeff(n , k) << endl;
}
