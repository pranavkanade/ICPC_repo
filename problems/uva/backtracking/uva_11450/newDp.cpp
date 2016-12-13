#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int m, c;
int k;
int price[25][25]; // price[garment_id][model]
int memo[210][25]; // memo[money_left][garment_id]


int shop(int money_left, int garment_id){
  if(money_left < 0)
    return -10000000; // fail, return large number
  if(garment_id == c)
    return m - money_left;
  if(memo[money_left][garment_id] != -1) // if this state has been visited
    return memo[money_left][garment_id]; // simply return
  int max_value = -10000000;
  for(int  model = 1; model < price[garment_id][0]; model++){
    int temp = shop(money_left - price[garment_id][i],
		    garment_id+1);
    max_value = max_value > temp ? max_value : temp;      
  }
  return memo[money_left][garment_i] = max_value;
}

int main(){
  int i, j, tc, score;

  cin >> tc;
  while(tc--){
    cin >> m >> c;
    for(i = 0; i < c; i++){
      cin >> k;
      price[i][0] = k; // to simplyfy store k in price[i][0];
      for(j = 1; j <= k; j++){
	cin >> price[i][j];
      }
    }

    memset(memo, -1, sizeof(memo)); // initialize memo;
    score = shop(m, 0); // start top down DP
    if(score < 0)
      cout << "no Solution" << endl;
    else
      cout << score << endl;
  }
}
