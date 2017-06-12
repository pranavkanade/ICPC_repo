#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define vec vector

int main(){
  int t;
  cin >> t;
  int n;
  vec<ll, vec<ll>> arrVec;

  while(t--){
    cin >> n;
    vec<ll> arrInp(n);
    for (int i = 0; i < n; i++){
      cin >> arrInp[i];
    }


    for(int i = 0; i < n; i ++){
      if(i == 0)
	arrVec.push_back(vec<ll>).push_back(arrInp[0]);
      else
	for(int j = 0; j < arrVec.size(); j++){
	  if(arrInp[j].last() > arrInp[i] && j == 0){
	    arrVec.insert(j, (vec<ll>)).push_back(arrInp[i]);
	    arrVec.erase(1);
	  }
	  else if(arrInp[j].last() < arrInp[i]){
	    
	  }
	  
	}
    }
  }  
}
