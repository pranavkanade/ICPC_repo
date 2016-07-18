#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <cstring>


using namespace std;

unordered_map<unsigned int,unsigned int> lis;
unordered_map<unsigned int,unsigned int> :: iterator it;

// int main(){
//   lis.insert({1,1});
//   unordered_map<unsigned int, unsigned int> :: iterator it;
//   it = lis.find(1);
//   cout << it->first << endl;
//   it->second = (it->second)++;
//   cout << it->second << endl;
//   int i = 0;
//   i = i++;
//   cout << "#" << i << endl;
//   lis.insert({2,it->second});
//   it = lis.find(2);
//   cout << it->second << endl;
//   return 0;
// }


unsigned int funlis(long int * arr, unsigned int n){
  unsigned int result = 0, temp = 0;
  if(n == 1)
    return 1;
  else {
    for(unsigned int i = 1; i < n; i++){
      it = lis.find(i);
      if(it == lis.end()){
	temp = funlis(arr, i);
	lis.insert({i, temp});
      }
      else
	temp = it->second;
      if(temp > result){
	result = temp;
      }
    }
    if(arr[n-1] > arr[n-2])
      result++;      
  }
  cout << "#" << result << endl;
  return result;
}

int main(){
   unsigned int t = 0;
   scanf("%d",&t);
   unsigned int n = 0;
  
   while(t != 0){
    scanf("%d", &n);
    long int arr[n];
    memset(arr, 0, n);

    for(unsigned int i = 0; i < n; i++){
      scanf("%ld",&arr[i]);
    }
    cout << funlis(arr, n) << endl; 
    t--;
   }

   return 0;
}
