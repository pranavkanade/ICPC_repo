#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli max(lli a, lli b){
  return (a > b ? a : b); 
}

lli rec(lli n, lli h){
  if(h == 0 && n > 0)
    return 0;
  else if(n == 1)
    return h;
  else if(h == 1)
    return 1;
  else{
    vector<lli> arr(h);
    for(int i = 0; i < h; i++){
      arr[i] = max(rec(n-1, i), rec(n, h - i - 1));
    }
    return (1 + *min_element(arr.begin(), arr.end()));
  }
}

int main(){
  lli n = 4;
  lli h = 20;

  cout << rec(n,h) << endl;
}
