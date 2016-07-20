#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct ele{
  int val;
  //e * next;
  ele * pre;
};

int main(){
  int n;
  cin >> n;
  vector<ele*> arr(n);
  vector<ele*> last(n);
  vector<int> len(n);
  for(int i = 0; i < n; i++){
    arr[i] = new ele();
    //last[i] = new ele();
    cin >> arr[i]->val;
    arr[i]->pre = NULL;
    last[i] = NULL;
    len[i] = 0;
  }
  int r = 0;
  last[0] = arr[0];
  len[0] = 1;
  int j = 0;
  for(int i = 1; i < n; i++){
    for(j = 0; j < last.capacity(); j++){
      if(last[j] == NULL || arr[i]->val <= last[j]->val){
	//cout << "#1" << endl;
	break;
      }
    }

    // if(j == 0){
    //   last.insert(last.begin()+j, arr[i]);
    //   len.insert(len.begin()+j, 1);
    //   //if(len[j] == len[j+1]){
    // 	len.erase(len.begin()+j+1);
    // 	last.erase(last.begin()+j+1);
      
    // }
    //else if(j == last.capacity()){
      // last.insert(last.begin()+j,arr[i]);
      // len.insert(len.begin()+j,len[j-1] + 1);
      // last[j;
      // if(len[j] == len[j+1]){
      // 	len.erase(len.begin()+j-1);
      // 	len.earse(
      // }
      last.insert(last.begin()+j,arr[i]);
      len.insert(len.begin()+j,len[j-1] + 1);
      if(len[j+1] != 0 && len[j+1] == len[j]){
	len.erase(len.begin()+j+1);
	last.erase(last.begin()+j+1);
	//last[j+1] = NULL;
      }
      last[j]->pre = last[j-1];
      //      int r = 0;
      
  }
  for(int p = 0; p < n; p++){
	
	if(len[p] > len[p+1]){
	  r = p;
	  break;
	}
      }
  ele * node = last[r];
  while(node != NULL){
    cout << node->val << " ";
    node = node->pre;
  }

  return 0;
  
}
