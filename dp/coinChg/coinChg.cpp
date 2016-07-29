#include <bits/stdc++.h>

using namespace std;
#define ulli unsigned long long int
#define lli long long int
#define uli unsigned long int
#define li long int

lli count(ulli * s, lli m, lli n){
  if(n == 0)
    return 1;
  else if(n < 0)
    return 0;
  else if(m <= 0 && n >= 1)
    return 0;
  else
    return count(s, m-1, n) + count(s, m, n - s[m-1]);
}

int main(){
  li s[3] = {1, 2, 3};

  li n;
  cin >> n;

  cout << count(s, 3, n) << endl;
  return 0;
}
