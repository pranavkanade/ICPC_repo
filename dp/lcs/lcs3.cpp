#include <bits/stdc++.h>


using namespace std;

int main(){
  char arr1[] = "AGGTAB";
  char arr2[] = "GXTXAYB";
  int n1 = strlen(arr1);
  int n2 = strlen(arr2);
  vector<vector<int>> table(n1 + 1, vector<int>(n2 + 1, 0));
  
  for(int i = 0; i <= n1; i++){
    for(int j = 0; j <= n2; j++){
      if(i == 0 || j == 0){ 
	table[i][j] = 0;
      } else if(arr1[i] == arr2[j]){
	//the following expressions are not similar;
	//table[i][j] = table[i-1][j-1]++;
	table[i][j] = table[i-1][j-1] + 1;
      } else{ 
	  table[i][j] = max(table[i][j-1], table[i-1][j]);;
      }	
    }
  }

  cout << "lcs : " << table[n1][n2] << endl;
  // int m = 0;
  // for(int i = 0 ; i < n1; i++){
  //   m = m <= table[i][n2] ? table[i][n2] : m; 
  // }
  // cout << "lcs : " << max(*max_element(table[n1-1].begin(), table[n1-1].end()),m);
  // for(int i = 0; i < n1; i++){
  //   for(int j = 0; j < n2; j++){
  //     cout << table[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  return 0;
}
