#include <iostream>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;


int main(){
    ll n;
    ll ans;
    cin >> n;
    ll points[n][2];
    ll sqx[n], sqy[n];
    ll x = 0, y = 0;
    ll temp1 = 0, temp2 = 0;
    for(ll i = 0; i < n; i++){
        cin >> points[i][0] >> points[i][1];
    }
    for(ll i = 0; i < n; i++){
      sqx[i] = points[i][0]*points[i][0];
      x += sqx[i];
      sqy[i] = points[i][1]*points[i][1];
      y += sqy[i];

      temp1 += points[i][0];
      temp2 += points[i][1];
    }
    ans = (n-1)*(x+y)*1LL;

    for(ll i = 0; i < n-1; i++){
      temp1 -= points[i][0];
      temp2 -= points[i][1];
      ans -= 2*(temp1 * points[i][0] + temp2 * points[i][1]);
    }
    
    printf("%lld\n",ans);
    return 0;
}
