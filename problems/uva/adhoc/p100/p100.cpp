#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//For any two numbers i and j you are to determine the maximum cycle length over all numbers between i and j. 
int main(){
  ll n1, m1;
  while(cin >> n1 >> m1){
    ll count = 0, c = 0;
    for(ll i = (n1>m1?m1:n1); i <= (m1>n1?m1:n1); i++){
      c = 0;
      ll n = i;
      while(n != 1){
	//cout << n << " ";
	++c;
	if(n % 2 == 1){
	  n = 3*n + 1;
	}
	else n = n/2;
      }
    //cout << n << endl;
      ++c;
      if(c >= count) count = c;
    }
    cout << n1 << " " << m1 << " " << count << endl;
  }
}
