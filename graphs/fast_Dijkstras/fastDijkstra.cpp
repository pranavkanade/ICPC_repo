#include <bits/stdc++.h>

using namespace std;

const int INF = 200000000;
typedef pair<int, int> PII;
typedef long long int ll;

int main(){
  int N, s, t; // N = no of nodes; s = start; t = target node;
  cin >> N >> s >> t;


  // adjecency list with the nodes and so the following allocation;
  // the graph has to be undirected or it can be directed
  // just mention all the nodes which are attached to curr node in the following format; 

  vector<vector<PII>> edges(N);

  for (int i = 0; i < N; i++) {
    int m;   // the m is no of edges attached to the ith node
    cin >> m;
    for(int j = 0; j < m; j++) {
      int vertex, dist;
      cin >> vertex >> dist;
      edges[i].push_back(make_pair(dist, vertex)); // note the order of argument;
    }
  }

  // use priority queue in which top element has the "smallest" priority ( key) i.e min-heap;

  priority_queue<PII, vector<PII>, greater<PII> > Q;

  vector<int> dist(N, INF), dad(N, -1);
  Q.push(make_pair(0,s));
  dist[s] = 0;

  // main logic can be transformed to function which will be independent;

  while(!Q.empty()){
    PII p = Q.top();
    Q.pop();
    int here = p.second;
    if(here == t) break;
    if(dist[here] != p.first) continue;

    for(vector<PII>::iterator it = edges[here].begin(); it != edges[here].end(); it++){
      if(dist[here] + it->first < dist[it->second]){
	dist[it->second] = dist[here] + it->first;
	dad[it->second] = here;
	Q.push(make_pair(dist[it->second], it->second));
      }
    }   
  }


  // the printing of the route is in the reverse order;
  cout << dist[t] << endl;
  if(dist[t] < INF){
    for(int i = t; i != -1; i = dad[i]){
      cout << i << (i==s? "\n" : " ");
    }
  }
    
  return 0;
}
