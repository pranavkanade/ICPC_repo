#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define vec vector


int main(){
  ll t = 0;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;

    ll temp = n % 8;
    ll qtemp = n - temp;

    if(temp == 0)
      cout << n - 1 << "SL"<< endl;
    else if(temp == 7)
      cout << n + 1 << "SU" << endl;
    else if(temp <= 3)
      cout << qtemp + temp + 3 ;
    else
      cout << qtemp + temp - 3 ;
    if(temp < 7 && temp != 0){
      if(temp % 3 == 1) cout << "LB" << endl;
      else if(temp % 3 == 2) cout << "MB" << endl;
      else if(temp % 3 == 0) cout << "UB" << endl;
    }
  }
}
