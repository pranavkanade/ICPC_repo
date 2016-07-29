// working of the substr() function must be noted;

#include <bits/stdc++.h>

using namespace std;

long int edit(string str1, string str2){
  unsigned long int n1 = str1.size();
  unsigned long int n2 = str2.size();
  
  long int ans = 0;
  long int ans1[3];

  // following conditions are also imp
  if(n1 == 0) return n2;
  if(n2 == 0) return n1;
  if(str1[n1-1] == str2[n2-1]){
    ans = edit(str1.substr(0,n1-1), str2.substr(0,n2-1));
  }
  else{
    ans1[0] = edit(str1.substr(0,n1-1), str2.substr(0,n2-1)); 
    ans1[1] = edit(str1.substr(0,n1), str2.substr(0,n2-1));
    ans1[2] = edit(str1.substr(0,n1-1), str2.substr(0,n2));
    ans = 1 + min(min(ans1[0], ans1[1]), ans1[2]);
  }
  return ans;  
}

int main(){
  string str1;
  string str2;

  cin >> str1;
  cin >> str2;
 
  long int ans = edit(str1, str2);
  cout << ans << endl;
  return 0;
}
