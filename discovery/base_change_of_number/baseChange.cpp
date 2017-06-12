#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int i0 = 48, i9 = 57; // ascii values of the nos
int a = 97, z = 122;
int A = 65, Z = 90;
struct Int{
  string val;
  int base;
};

int main(){
  Int n;
  cin >> n.base >> n.val;
  int outBase;
  cin >> outBase;

  int intermediate_base = 10;

  ll org_val = 0; // value of original no in decimal form;
  ll org_base = n.base;
  //cout << "%*&^ " << (int)('a')  << " " << (int)'z'<< endl;
  for(int i = 0; i < n.val.size(); i++){
    char temp = n.val[n.val.size() - 1 - i];
    //cout << "&& " << temp << endl;
    int ti = (int) temp;
    //cout << "** " << ti << endl; 
    if(ti <= i9 && ti >= i0){
      ti = ti - i0;
    }
    else if(ti <= z && ti >= a){
      ti = ti - a + 10;
    }
    else if(ti <= Z && ti >= A){
      ti = ti - A + 10;
    }
    
    org_val += ti * pow(n.base, i);
    //cout << "** " <<  org_val << endl;
  }
  cout << " && " << endl;
  cout << org_val << endl;

  vll m;
  int quo  = outBase + 1;
  while(org_val > outBase){
    ll rem = org_val % outBase;
    m.push_back(rem);
    org_val = org_val / outBase;
  }
  m.push_back(org_val);
  
  //string val;
  vector<char> value;
  for(int j = m.size() - 1; j >= 0; j--){
    if(m[j] >= 10){
      value.push_back((char)(55 + m[j]));
    }
    else
      value.push_back((char)(48 + m[j]));
  }
  //cout << " ** " << endl;
  for(int i = 0; i < value.size(); i++){
    cout << value[i];
  }
  cout << endl;
  return 0;
}
