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

//int knownPrimes[] = {2, 3, 5, 7, 11};

void sieve(int n){
  bool prime[n+1];
  memset(prime, true, sizeof(prime));

  for(int p = 2; p * p < n; p++){
    if(prime[p] == true){
      // update all the multiples of p;
      for(int i = p*2; i<=n; i+=p){
	prime[i] = false;
      }
    }
  }

  for(int p = 2; p <=n; p++){
    if(prime[p])
      cout << p << " ";
  }
}

