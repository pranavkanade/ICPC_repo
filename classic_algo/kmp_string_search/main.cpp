# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll prefixFunction(string inpPatt, vll piArr){
  int j = 0;
  for (int i = 1; i < inpPatt.size(); i++){
    if(inpPatt[i] == inpPatt[j]){
      piArr[i] = piArr[j-1] + 1;
      j++;
    }
    else if(j > 0){
      j = piArr[j-1];
      i--;
    }
    else{
      piArr[i] = 0;
    }
  }
  return piArr;
}


vll kmpSearch(&string inpTxt, &string inpPatt, &vll piArr){
  vll out;
  ll j = 0;
  for(int i = 0; i < inpTxt.size(); i++){
    if(inpPatt[j] == inpTxt[i]){
      j++;
      if(j == inpPatt.size()){
        out.push(i-j-1);
        j = piArr[j];
      }
    }else{
      j = piArr[j - 1];
      i--;
    }
  }
  return out;
}

int main(){
  string inpTxt;
  cin >> inpTxt;
  string inpPatt;
  cin >> inpPatt;

  vll piArr(inpPatt.size(), 0);

  prefixFunction(piArr);

  vll out = kmpSearch(inpTxt, inpPatt, piArr);

  for (auto a : out){
    cout << a << " ";
  }
}
