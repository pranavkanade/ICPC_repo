#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef vector<ll> vll;
typedef vector<bool> vbool;
typedef vector<vll> vvll;
typedef pair<ll, ll> pl;
typedef pair<ll , pl> plpl;
typedef vector<pl> vpl;
typedef vector<plpl> vplpl;
typedef priority_queue<pl, vpl> maxH;
typedef priority_queue<pl, vpl, greater<pl>> minH;

#define mp(i, j) make_pair((i), (j))
#define pb(i) push_back(i)
#define vec vector

int initialNode = 0;
      

int main(){
  ll t = 0, z = 0;
  scanf("%lld", &t);
  ll a, b, c;
  ll n, m;
  while(t--){
    scanf("%lld %lld", &n, &m);
    vvll graph(n, vll(n, 0));
    vll deg(n,0);
    for(ll i = 0; i < m; i ++){
      scanf("%lld %lld %lld", &a, &b, &c);
      //cout << a << " " << b << " " << c << endl;
      b = b-1;
      a = a-1;
      deg[a]++;
      deg[b]++;
      graph[a][b] = c;
      graph[b][a] = c;
    }
    ll sol = 1000000000;
    bool temp = false;
    for(int i = 0; i < n; i++){
      if(deg[i] == 0){
	temp = true;
	sol = 0;
      }
    }
    
    // stoer-wagner
    //ll V = n;
    vbool merged(n, false);
    for(int i = 0; i < n-1; i++){
      vbool merged(n, false);
      int last = 0, last_1 = -1;
      int expectedSize = n - i;
      vbool visited = merged;
      ll cut = 0;
      // for each merging .. following loop will merge last elm at the end of it;
      for(int j = 1; j < expectedSize; j++){
	cut = 0;
	last_1 = last;
	visited[last] = true;

	for(int k = 0; k < n; k++){
	  if(!visited[k] && (graph[last_1][last] < graph[last_1][k])) last = k;
	}
	//cout << " ============================================> last : " << i << " : " << last << endl;
	if(j == expectedSize - 1){
	  cout << " $$$$$$$$ " << last_1 << " " << last << endl;
	  // merge last and last_1
	  merged[last] = true;
	  for(int k = 0; k < n; k ++){
	    cut += graph[last][k];
	  }
	  if(sol > cut){
	    sol = cut;
	  }
	  // graph[last_1][last] = 0;
	  cut += graph[last][last_1];
	  //graph[last][last_1] = 0;
	  for(int k = 0; k < n; k++){
	    graph[last_1][k] += graph[last][k];
	  }
	  for(int k = 0; k < n; k++){
	    graph[k][last_1] = graph[last_1][k];
	  }
	  cout << endl; 
	  for(int k = 0; k < n; k++){
	    for(int l = 0; l < n; l++){
	      cout << graph[k][l] << " ";
	    }
	    cout << endl;
	  }
	  
	  //cout << "#########################> " << sol << endl;
	}
      }

      // for(int k = 0; k < n; k++){
      // 	for(int l = 0; l < n; l++){
      // 	  cout << graph[k][l] << "  ";
      // 	}
      // 	cout << endl;
      // }

      //cout << endl << endl;
    }
    
    printf("Case #%lld: %lld\n", ++z, sol);
  }
  return 0;
}
