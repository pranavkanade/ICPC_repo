// ugly no problem; nos which are only divisible with 2,3,5 thats it.
// this my 1st DP problem;

// my strategy is to store the pattern like
//$# 1,,[2,3,2*2,5,2*3,3*3,2*5,3*5,5*5] -> and then this pattern will repeate;
// abouve strategy is flaud and it puts us in n2 complexity


#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

vector<int> ugly;
long int minu(long int ch2, long int ch3, long int ch5){
  if(ch2 <= ch3){
    if(ch2 <= ch5){
      return ch2;
    }else
      return ch5;
  }else if (ch3 <= ch5)
    return ch3;
  else
    return ch5;   
}

int main(){
  long int t = 0;
  ugly.push_back(1);
  
  scanf("%ld", &t);
  long int num = -1;
  long int max = 0;
  long int i2 = 0, i3 = 0, i5 = 0;
  long int ch2, ch3, ch5, nu;
  
  while(t != 0){
    cin >> num;
    max = ugly.size();
    
    if(num < max)
      cout << ugly[num] << endl;
    else{
      ch2 = ugly[i2] * 2;
      ch3 = ugly[i3] * 3;
      ch5 = ugly[i5] * 5;
      for(long int i = max ; i < num; i++){
	nu = minu( ch2, ch3, ch5);
	ugly.push_back(nu);
	if(nu == ch2){
	  i2++;
	  ch2 = ugly[i2]*2;
	}
	if(nu == ch3){
	  i3++;
	  ch3 = ugly[i3]*3;
	}
	if(nu == ch5){
	  i5++;
	  ch5 = ugly[i5]*5;
	}
      }

      cout << ugly[num-1] << endl;
    }
    t--;
  }
  return 0;
}
