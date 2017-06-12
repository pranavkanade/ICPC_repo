#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<pl, ll> ppl;
typedef pair<ll, pl> plpl;
typedef vector<ll> vll;
typedef vector<bool> vbl;
typedef vector<vll> vvll;
typedef vector<pl> vpl;
typedef priority_queue<pl, vpl> maxH;
typedef priority_queue<pl, vpl, greater<pl>> minH;

#define mp(i, j) make_pair((i), (j))
#define pb(i) push_back(i)
#define vec vector


int main() {
    ll t = 0;
    cin >> t;
    ll n, m;
    //while(t--){
        cin >> n >> m;
        vll arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vvll tab(n+1, vll(n+1, 0));

        for(int i = 1; i <= n; i ++){
            for(int j = i; j <= n; j ++){
                cout << "i : " << i << " j : " << j << endl;
                //if(i == 1){
                    tab[i][j] += tab[i][j-1] + arr[j-1];
//                } else
//                    tab[i][j] = tab[i-1][j] - arr[j-1];
            }
        }
//    cout << "hi " << endl;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                cout << tab[i][j] << "\t";
            }
            cout << endl;
        }
    //}
    return 0;
}