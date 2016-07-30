#include <iostream>
#include <vector>

using namespace std;

#define ulli unsigned long long int

vector<ulli> arr;

int atk(ulli n){
  vector<bool> s(n, false);
  ulli m = 0;
  if(n > 2) arr.push_back(2);
  if(n > 3) arr.push_back(3);
  
  for(ulli i = 1; i*i < n; i++){
    for(ulli j = 1; j*j < n; j++){
      m = (j*j) + (4 * i * i);
      if(m <= n && (m %12 == 1 || m % 12 == 5))
	s[m] = s[m] ^ true;
      m = (j*j) + (3 * i * i);
      if(m <= n && m % 12 == 7)
	s[m] = s[m] ^ true;
      m = (3* i * i) - (j * j);
      if(i > j && m <= n && m % 12 == 11)
	s[n] = s[m] ^ true;
    }
  }

  for(ulli i = 5; i*i < n; i++){
    if(s[i]){
      for(ulli j = i*i; j < n; j += i*i)
	s[j] = false;
    }
  }

  for(ulli a = 5; a < n; a++)
    if (s[a])
      arr.push_back(a);
}


int main(){
	ulli n = 100;
	atk(100);
	for(ulli i = 0; i < arr.size(); i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
	return 0;
}
