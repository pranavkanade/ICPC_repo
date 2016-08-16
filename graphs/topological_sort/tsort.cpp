#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define vec vector

#define outi(i) printf("%lld ", i)

struct vertex{
  lli indeg = 0;
  vec<lli> al;
};

class graph{
  vec<vertex> *node;
  lli n;
public:
  graph(lli n){
    this->n = n;
    node = new vec<vertex>(n+1);
  }

  void addEdge(lli p, lli q){
    node[q]->indeg++;
    (node[p].al).push_back(q);
  }

  void tsort(){
    list<lli> s;
    vec<lli> done;
    vec<bool> l;

    for(lli i = 1; i < n; i++)
      if(node[i].indeg == 0)
	s.push_back(i);
    
    while(!s.empty()){
      
      vec<lli> * all;

      done.push_back(s.front());
      s.pop_front();
      all = &node[done.back()].al;
	for(int m = 0; m < all->size(); m++){
	node[all[m]]->indeg--;
	if(node[all[m]]->indeg == 0)
	  s.push_back(all[m]);
      }
    }

    for(lli j = 0; j < done.size(); j++){
      cout << done[j] << " ";
      //out(done[i]);
    }
    cout << endl;
  }
};


int main(){
  graph g(20);
  return 0;
}
