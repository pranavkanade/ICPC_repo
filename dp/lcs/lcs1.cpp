//recurrsive iimplementation


#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int lcs(char * arr1, char* arr2, int n1, int n2){
  if(n1 == 0 || n2 == 0)
    return 0;
  if(arr1[n1] == arr2[n2]){
    return 1+lcs(arr1, arr2, n1-1, n2-1);
  }else{
    return max(lcs(arr1, arr2, n1, n2-1), lcs(arr1, arr2,n1-1, n2));
  }
}

int main(){
  char arr1[] = "aggtab";
  char arr2[] = "gxtxayb";
  cout << "prq" << endl;
  int p = lcs(arr1, arr2, strlen(arr1), strlen(arr2));
  cout << "length : " << p << endl;
  return 0;
}
