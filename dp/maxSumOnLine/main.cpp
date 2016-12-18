#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vll, greater<>> minHeap;
typedef priority_queue<ll, vll> maxHeap;

#define vec vector

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  int m[1000];
  int indx;
  ll sum;
  while(tc--){
    ll n;
    cin >> n;
    ll arr[n];
    for(int i=0; i < n; i++){
      cin >> arr[i];
    }
    memset(m, 0, sizeof(m));
    sum = 0; indx = 0;
    m[0]=arr[0];
    sum = m[0];
    ll temp;
    for(int i= 1; i < n; i++){
      m[i] = (arr[i] < (temp = arr[i] + m[i-1]))
	? temp
	: arr[i];
      if(m[i] > sum){
	sum = m[i];
	indx = i;
      }
    }

    cout << "partial sum = " << sum << " till index : " << indx << "\n";
  }
}
