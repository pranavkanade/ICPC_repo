#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <cstring>


using namespace std;

unordered_map<unsigned int,unsigned int> lis;

int main(){
  lis.insert({1,1});
  unordered_map<unsigned int, unsigned int> :: iterator it;
  it = lis.find(1);
  cout << it->first << endl;
  it->second = (it->second)++;
  cout << it->second << endl;
  int i = 0; // this is the facinating code the output of 19, 20 and 21 should be calculated;
  i = i++;
  cout << "#" << i << endl;
  lis.insert({2,it->second});
  it = lis.find(2);
  cout << it->second << endl;
  return 0;
}
