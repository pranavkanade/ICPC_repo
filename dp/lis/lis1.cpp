
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long int n;
  scanf("%ld", &n);
  vector<long int> arr;
  vector<long int> last;
  vector<long int> len(n);
  long int m;
  for(int i = 0; i < n; i++){
    scanf("%ld", &m);
    arr.push_back(m);
  }
  int r = 0;
  last.push_back(arr[0]);
  len[0] = 1;
  long int j = 0;
  for(long int i = 1; i < n; i++){
    j = lower_bound(last.begin(), last.end(), arr[i]) - last.begin();
    //if(arr[i] != last[j]){
    // cout << "#" << j << endl;
      last.insert(last.begin()+j,arr[i]);
      if(j != 0)
	len.insert(len.begin()+j,len[j-1] + 1);
      else
	len.insert(len.begin(),1);
      if(len[j+1] == len[j]){
  	len.erase(len.begin()+j+1);
  	last.erase(last.begin()+j+1);
      }
    //   cout << "len : ";
    // for(int s = 0; s < last.capacity(); s++){
    //   cout << len[s] << " ";
    // }
    // cout << endl << "last : ";
    // for(int s = 0; s < last.capacity(); s++){
    //   cout << last[s] << " ";
    // }
    // cout << endl;
  }

  printf("%ld\n", *max_element(len.begin(), len.end()) );
  return 0;
  
}
