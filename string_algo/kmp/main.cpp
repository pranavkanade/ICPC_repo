# include <iostream>
# include <vector>
# include <algorithm>
# include <string>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int preprocessing(string pattern, vll & processedOpArr){
  ll patternLength = pattern.size();

  cout << patternLength << endl;
  ll matchPointer = 0;
  for(int i = 1; i < patternLength; i++){

    while(matchPointer > 0 && pattern[matchPointer] != pattern[i]){
      matchPointer = processedOpArr[matchPointer-1];
    }
    if(pattern[matchPointer] == pattern[i]){
      matchPointer++;
    }
    processedOpArr[i] = matchPointer;
  }
  cout << "preprocessed" << endl;

  // return processedOpArr;
}


int matching(string pattern, string text, vll & answer){
  vll processedOpArr(pattern.size(), 0);
  preprocessing(pattern, processedOpArr);
  ll matchPointer = 0;

  
  for (int i = 0; i < text.size(); i++){
    while(matchPointer > 0 && pattern[matchPointer] != text[i]){
      matchPointer = processedOpArr[matchPointer-1];
    }
    if(pattern[matchPointer] == text[i]){
      if (matchPointer == pattern.size() - 1){
        matchPointer = processedOpArr[matchPointer];
        answer.push_back(i - pattern.size());
      }
      else
        matchPointer++;
    }
  }
 
  cout << "matched" << endl;
}

int main(){
  string text;
  cin >> text;

  string pattern;
  cin >> pattern;

  vll answer;
  matching(pattern, text, answer);

  for (auto item : answer){
    cout << item +1 << "\t";
  }
  cout << endl;
  return 0;
}
