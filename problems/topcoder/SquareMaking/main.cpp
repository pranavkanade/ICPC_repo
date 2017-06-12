#include <iostream>
#include <math.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){
	ll lim;
	cin >> lim;

	ll pac[4];
	while(lim--){
		ll tempTotal = 0;
		for(int i = 0; i< 4; i++){
			cin >> pac[i];
			tempTotal += pac[i];
		}
		ld tempAvg = tempTotal/4.0;

		ll ceil = round(tempAvg);
		ll ans = 0;
		for(int i = 0; i < 4; i++){
			ll temp = ciel - pac[i];
			ans += ciel >= 0 ? ciel : ciel * -1;
		}
		cout << ans;
		for (int i = 0; i < 4; i++){
			pac[i] = 0;
		}
	}
}