#include <bits/stdc++.h>

using namespace std;
//#define ulli long long int;

long long int cmc(vector<int> arr, int i, int n){
  if(i == n)
    return 0;
  long long int min = INT_MAX;

  for(int j = i; j < n; j++){
    long long int m = cmc(arr, i, j) + cmc(arr, j+1, n) + (arr[i-1] * arr[j] * arr[n]);

    if(min > m)
      min = m;
  }

  return min;
}


int main(){
  vector<int> arr = {1, 2, 3, 4, 3};

  int n = arr.size();

  cout << cmc(arr, 1, n-1) << endl;

}
