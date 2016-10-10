#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

int getParent(int i){
    return (i - (i & (-i)));
}

int getNext(int i){
    return (i + (i & (-i)));
}

void update(int indx, ll valDiff, vll & biTree){
    biTree[indx] += valDiff;
    indx = getNext(indx);
    if(indx < biTree.size()){
        update(indx, valDiff, biTree);
    }
    return;
}


//constructs tree
void constructTree(int i, vll & arr, vll & biTree){
    int p = 0;
    int tempi = i;
    while(tempi%2 == 0){
        p++;
        tempi = tempi/2;
    }
    int powerI = pow(2, p);
    tempi = i - powerI;
    for(int j = tempi; j < tempi + powerI; j++){
        biTree[i] += arr[j];
    }
}

// this gives sum of the elements from i to j both included
ll getSum(int i, int j, vll & biTree){
    ll sum1 = 0;
    ll sum2 = 0;
    j++;
    sum1 = biTree[j];
    while((j = getParent(j)) != 0){
        sum1 += biTree[j];
        //j = getParent(j);
    }
    sum2 = biTree[i];
    while((i = getParent(i)) != 0){
        sum2 += biTree[i];
        //i = getParent(i);
    }
    return sum1 - sum2;
}

int main(){
    vll arr = {2, 3, 4, 5, 6, 7, 8, 9};

    vll biTree(arr.size() + 1, 0);

    for(int i = 1; i < biTree.size(); i++){
        constructTree(i, arr, biTree);
    }

    int updateIndx = 0;
    ll updateValTo = 7;

    update(updateIndx + 1, updateValTo - arr[updateIndx], biTree);

    for(int i = 0; i < biTree.size(); i ++){
        cout << biTree[i] << endl;
    }


    for(int i = 0; i < arr.size(); i++){
        cout << "sum (0, "<< i << ") : " << getSum(0, i, biTree) << endl;
    }
    //cout << "parent Of 0" << getParent(0);

    cout << "sum ( 4, 7) : " << getSum(4, 7, biTree) << endl;

    return 0;
}