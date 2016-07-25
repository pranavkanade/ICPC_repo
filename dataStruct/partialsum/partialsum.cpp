#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
  long int n, q, a, b;

  int f1, f2;

  cin >> n >> q;
  cin >> f1 >> f2;
  cin >> a >> b;

  vector<long int> arr(n+1);
  vector<long int> f(3);
  f[0] = 0;
  f[1] = f1;
  f[2] = f2;
  
  long int * temp;
  arr[0] = 0;
  for(long int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  int d;
  long int l, r;
  while(q != 0){
    cin >> l >> r;
    d = r-l+1;
    if(f.size() < d){
      for(long int i = f.size(); i <= d ; i++){
	f.push_back(a*f[i-2] + b*f[i - 1]);
      }
    }
    temp = new long int[n+1];
     
    for(long int i = l; i <= r; i++){
      temp[i] = f[i-l+1];
    }

    for(long int i = l; i <=r; i++){
      arr[i] = arr[i] + temp[i];
    }
    q--;
  }
  for(long int i = 1; i <= n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
