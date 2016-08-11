#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define vec vector

void swap(char * a, char * b){
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

bool is_present(vec<char> & v, const char &a)
{
  for(int i = 0; i < v.size(); i++){
    if(a == v[i])
      return true;
  }
  return false;
}

template<typename T>
void print(const T& cont){
  for(lli i = 0; i < cont.size(); i++){
    cout << cont[i] << " ";
  }
  cout << endl;
}

void permute(char* str, lli len, lli s, lli & count){
 
  if(s == len){
    //cout << str << endl;
    count++;
  }
  else {
    vec<char> v;
    for(lli i = s; i < len; i++){
      if(i == s){
      	v.push_back(*(str+i));
      	permute(str, len, s+1, count);
      }else if(*(str+s) != *(str+i) && !is_present(v, *(str+i))){
      	v.push_back(*(str+i));
	//	cout << "## " << s << " : "; 
	//	print(v);
      	swap(str+s, str+i);
      	permute(str, len, s+1, count);
      	swap(str+s, str+i);
	
      } 
    }
  }
}

int main(){
  char str[] = "pranav";
  lli len = sizeof(str)/sizeof(char);
  lli count = 0;
  // cout << len << endl << endl;
  permute(str, len-1, 0, count);
  cout << count << endl;
  return 0;
}
