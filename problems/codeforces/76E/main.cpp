#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main() {
   ll n;
   cin >> n;
   //   scanf("%lld",&n);
//   scanf("%I64d",&n);
   cin >> n;

   ull ans = 0;
   ll xi, yi;
   //vector<pair<ll, ll>> points(n);
   ll points[n][2];

   for(int i = 0; i < n; i++){
       cin >> points[i][0] >> points[i][1];
       //scanf("%I64d %I64d", &points[i][0], &points[i][1]);
       //scanf("%lld %lld", &points[i].first, &points[i].second);
   }

   for(int i = 0; i < n; i++){
       for(int j = i+1; j < n; j++){
           xi = points[i][0] - points[j][0];
           yi = points[i][1] - points[j][1];
           ans += xi*xi + yi*yi;
       }
   }

   cout << ans;
   return 0;
}
