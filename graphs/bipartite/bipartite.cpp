#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpl;

#define vec vector

bool dfs(vll& graph1, ll p,ll i, vll& visited, vll& part, vvll & graph){
  visited[i] = 1;
  part[i] = p;
  bool temp = true;
  for(int m = 0; m < graph1.size(); m++){
    if(visited[graph1[m]] == 0){
      temp &= dfs(graph[graph1[m]], 1 - p, graph1[m], visited, part, graph);
      if(!temp)
	break;
    }
    else{
      if(part[graph1[m]] == part[i]){
	temp &= false;
	break;
      }
    }    
  }
  return temp;
}

int main(){
  // nodes start from 0 to N-1;
  ll N; // no of nodes
  cin >> N;
  
  vll visited(N, 0);
  vll part(N);
  //vvpl graph(N); //adjecency list; => for graph with weighted edges
  vvll graph(N); // for graph with non weighted edges;

  int m;
  ll f, s;
  for(int i = 0; i < N; i ++ ){
    cin >> m;
    for(ll j = 0; j < m; j++){
      //cin >> f >> s;  // vertex and distance from i;
      //graph[i].push_back(make_pair(f,s));

      cin >> f; // vertex adj to i;
      graph[i].push_back(f);
    }
  }
  bool temp = true;
  for(int i = 0; i < N; i++){
    if(visited[i] != 1){
      temp &= dfs(graph[i], 0, i, visited, part, graph);
      cout << " # " << i << " => " << temp << endl;
      if(!temp)
	break;
    }
  }
  if(temp)
    cout << "graph is bipartite";
  else
    cout << "graph is not bipartite";

  return 0;
}
