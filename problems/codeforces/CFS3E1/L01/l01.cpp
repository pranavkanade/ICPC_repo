#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ld penalty = 0.0;

ld squareRoot(ld n)
{
  ld x = n;
  ld y = 1;
  ld e = 0.00000001; 
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
void swap(int8_t & a, int8_t & b){
  int8_t temp;
  temp = a;
  a = b;
  b = temp;
}

int main(){
  string st;
  cin >> st;
  
  vector<int8_t> arr(st.length());


  for(ll i = 0; i < st.length(); i++){
    arr[i] = st[i];
  }
  
  ll last = st.length() -1;
  ll first = 0;

  while(true){
    if(arr[first] == '1' && arr[last] == '0'){
      swap(arr[first], arr[last]);
      penalty += squareRoot(last - first);
      first++;
      last--;
    }
    else if(arr[first] == '0'){
      first++;
    }
    else if(arr[last] == '1'){
      last--;
    }

    if(first >= last)
      break;
  }
  cout.precision(13);
  cout << penalty << endl;
  return 0;
}
