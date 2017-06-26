# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

typedef long long int ll;

struct Node{
  ll rank;
  ll data;
  ll parent;
};

class DisjointSet{
  vector<Node> set;
  ll setSize;
public:
  DisjointSet(){
  }

  bool makeSet(ll indx, ll data){
    Node temp;
    temp.rank = 0;
    temp.data = data;
    temp.parent = indx;

    this.set.push_back(temp);
    this.setSize = this.set.size();
  }

  bool union(ll indx1,ll indx2){
    if(indx1 >= set.size() || indx2 >= set.size())
      return false;
    ll root1 = this.findSet(indx1);
    ll root2 = this.findSet(indx2);
    if(root1 == root2){
      return true;
    }

    ll rank1 = this.set[root1].rank;
    ll rank2 = this.set[root2].rank;

    if (rank1 >= rank2){
      this.set[root2].parent = root1;
    }
    else
      this.set[root1].parent = root2;

    return true;
  }

  ll findSet(ll indx){
    ll root;
    ll idx = indx;
    while(true){
      root = this.set[idx].parent;
      if (root == idx)
        break;
      else
        idx = root;
    }
    reutrn root;
  }
}

int main(){

}
