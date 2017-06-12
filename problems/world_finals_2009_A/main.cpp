#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vll> vvll;
typedef priority_queue<pair<ll, ll>, vpll, greater<pair<ll, ll>>> min_pair_heap;
typedef priority_queue<pair<ll, ll>, vpll> max_pair_heap;

int inp = -1;

void fun(min_pair_heap & sHeap, max_pair_heap & fHeap, vll & result){

    int count = 1;
    while (count - 1 <= inp - count){
        result[count-1] = sHeap.top().second;
        result[inp - count] = fHeap.top().second;
        count ++;
    }


}

int main() {
    int ai, bi;
    while(inp != 0){
        cin >> inp;
        vector<bool> note(inp, false);
        //int arr[inp][2];
        vvll arr(inp, vll(2));
        min_pair_heap sHeap;
        max_pair_heap fHeap;
        for(int i = 0; i < inp; i ++){
            cin >> arr[i][0] >> arr[i][1];
            sHeap.push(make_pair(arr[i][0], i));
            fHeap.push(make_pair(arr[i][1], i));
        }
        vll result(inp);
        fun(sHeap, fHeap, result);

    }
    return 0;
}