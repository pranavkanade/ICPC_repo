#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
#define mp(i,j) make_pair(i , j)

int main(){
  priority_queue<pll, vector<pll>, greater<pll> > que;
  que.push(mp(5,4));
  que.push(mp(3,1));
  que.push(mp(7,3));
  priority_queue<pll, vector<pll>, greater<pll> > que1;
 
  pll temp;
  while(!que.empty()){
    temp = que.top();
    cout << temp.first << endl;
    que.pop();
  }

  que1 = que;
  cout << que1.empty() << endl;
  while(!que1.empty()){
    temp = que1.top();
    cout << temp.first << endl;
    que1.pop();
  }
  
  return 0;
}
