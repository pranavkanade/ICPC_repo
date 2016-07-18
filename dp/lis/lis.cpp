#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <cstring>


using namespace std;

//unordered_map<int,int> lis;

unsigned int funlis(long int * arr, unsigned int n){
  unsigned int result = 0, temp = 0;
  if(n == 1)
    return 1;
  else {
    /*
    if(arr[n-1] > arr[n-2]){
      for(unsigned int i = 1; i < n; i++){
	temp = funlis(arr, i);
	if(temp > result){
	  result = temp;
	}
      }
      result++;
    }
    else{
      for(unsigned int i = 1; i < n; i++){
	temp = funlis(arr, i);
	if(temp > result){
	  result = temp;
	}
      }
    }
    */
    for(unsigned int i = 1; i < n; i++){
      temp = funlis(arr, i);
      if(temp > result){
	result = temp;
      }
    }
    if(arr[n-1] > arr[n-2])
      result++;      
  }
    //cout << "#" << result << endl;
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
