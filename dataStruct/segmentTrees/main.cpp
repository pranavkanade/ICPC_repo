#include <bits/stdc++.h>
using namespace std;


int getSum(int * st, int start, int end, int qStart, int qEnd, int pos){
    // if the segment of this node is part of the given range
    if (qStart <= start && qEnd >= end){
        return st[pos];
    }

    // on overlap
    if(qStart > end || qEnd < start){
        return 0;
    }

    int mid = start + (end - start)/2;
    return getSum(st, start, mid, qStart, qEnd, 2 * pos + 1) +
           getSum(st, mid + 1, end, qStart, qEnd, 2* pos + 2);
}

// arr -> initial array
// st -> segment tree arr
// n -> size of arr;
// i -> index to be updated

void updateSegTreeUtil(int * st, int start, int end, int i, int diff, int pos){
    if(i < start || i > end){
        return;
    }

    // if the input node is in the range betn start and end;
    // then update the val of node and its children;
    st[pos] = st[pos] + diff;
    if(start != end){
        int mid = start + (end - start)/2;
        updateSegTreeUtil(st, start, mid, i, diff, 2 * pos + 1);
        updateSegTreeUtil(st, mid+1, end, i, diff, 2 * pos + 2);
    }
}

void updateSegTree(int arr[], int * st, int n, int i, int new_val){
    // invalid operation update index out of bound
    if(i < 0 || i > n-1){
        cout << " invalid index" << endl;
        return;
    }

    int diff = new_val - arr[i];
    // update to the original array;
    arr[i] = new_val;

    // update to the whole seg Tree;
    updateSegTreeUtil(st, 0, n-1, i, diff, 0);
}


// pos is current position of the node on which the function is operational;
// start -> start index of the given arr; to get the sub arr;
// end -> last index of the given arr; to get the sub arr;

int segTreeUtil(int arr[], int start, int end, int * st, int pos){
    // check if there is only one element in the array; (start of arr == end of the arr)
    if(start == end){
        st[pos] = arr[start];
        return arr[start];
    }

    // if there are more than single element then recursion for left and right
    // subtrees and store the sum of values of this node;
    int mid = start + (end - start)/2;
    // position of the root starts from pos == 0;
    st[pos] = segTreeUtil(arr, start, mid, st, pos * 2 + 1) + segTreeUtil(arr, mid+1, end, st, pos*2 + 2);
    return st[pos];
}


int * segTree(int arr[], int n){
    // To get the size of the tree
    // findthe height of the tree;
    int ht = (int)(ceil(log2(n)));
 //   cout << "ht : " << ht << endl;
    // maximum size of the arr in which the tree is going to be stored;
    int max_size = 2*(int)pow(2,ht) -1;
   // cout << "max size : " << max_size << endl;

    int *st = new int[max_size];
    //cout << "size of st : " << sizeof(st) << endl;

    segTreeUtil(arr, 0, n-1, st, 0);
    return st;
}



int main() {
    int arr [] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/ sizeof(arr[0]);

    int *st = segTree(arr, n);

    cout << getSum(st, 0, n-1, 1, 3, 0) << endl;

    updateSegTree(arr, st, n, 2, 2);



    for(int i = 0; i < 15; i++){
        cout << st[i] << " ";
    }
    cout << endl;
    return 0;
}