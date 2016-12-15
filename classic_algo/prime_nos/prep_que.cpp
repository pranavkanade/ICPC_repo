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

int knownPrimes[] = {2, 3, 5, 7, 11};

ll sieve(ll a, ll n, ll k){
  ll arr[n*n];
  memset(arr, 0, sizeof(arr));
  arr[0] = a;
  // make an array containing integers which will ultimately have the factor k;
  for(ll i = 1; i < n*n; i++){
    arr[i] = a + k * i;
  }
  ll counter = 0, l = 0, m, j = 0;


  // eliminate all factors of nos which are less than k;
  // if k = 5;
  // then if 15 is in the list = 3 * 5;
  // eliminate 3 only keep 5
  // if 75 is in the list = 3 * 5 * 5;
  // eliminate 3 only keep 5 * 5;
  
  while(knownPrimes[j] < k){
    for(ll i = 0; i < n*n; i++){
      while(arr[i] % knownPrimes[j] == 0){
	if(arr[i] == 1){
	  break;
	}
	else{
	  arr[i] = arr[i]/knownPrimes[j];
	}
      }
    }
    j++;
  }


  // find out all the elements with only k as a remaining factor;
  for(ll i = 0; i < n*n; i++){
    while(arr[i] % k == 0)
      arr[i] = arr[i]/k;
    if(arr[i] == 1)
      counter++;
    if(counter == n){
      m = i;
      break;
    }
  }
  // return the no at the index 'i' where counter == n;
  return a + k * m;
}


int main(){
  ll tc;
  cin >> tc;

  ll a, n, k, m;
  while(tc--){
    cin >> a >> n >> k;
    // find the next no >= a which has k as a factor;
    if(a%k != 0){
      m = a/k + 1;
      a = k*m;
    }

    cout << sieve(a, n, k) << endl;
  }
}
