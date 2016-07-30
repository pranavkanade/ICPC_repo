#include <bits/stdc++.h>

using namespace std;

#define ulli unsigned long long int
#define lli long long int
#define li long int


lli count(vector<lli> s, lli size, lli n){
  if(n == 0)
    return 1;
  if(size == 0)
    return 0;
  if(n < 0)
    return 0;
  if(n > 0 && size > 0){
    return (count(s, size, n-s[size-1]) + count(s, size-1, n));
  }
}


int main(){
  vector<lli> s = {1, 2, 3};

  lli n;
  cin >> n;

  cout << count(s, 3, n) << endl;
  return 0;
}
