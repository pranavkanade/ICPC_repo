#include <iostream>
#include <vector>

using namespace std;
#define vec vector

// Format Specifiers
#define plong "%lld"
#define pc "%c"
#define pld "%Lf"
#define pllu "%llu"
#define newl printf("\n")

//typedefs
typedef long long int ll;
typedef long double ld;

typedef vec<ll> vll;
typedef vec<vll> vvll;
typedef pair<ll, ll> pll;
typedef vec<pll> vpll;
typedef vec<vpll> vvpll;

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back(a)

int main(){
    ll inpt;
    //ll sum;
    while((cin >> inpt), inpt != -1){
        if(inpt == 0 || inpt % 2 == 1){
            cout << "0" << endl;
            continue;
        }
        ll inp = inpt/2;
        vll dpTab(inp+1);
        dpTab[0] = 1;
        dpTab[1] = 3;
        for(ll p = 2; p <= inp; p++){
            dpTab[p] = dpTab[p-1] * 4 - dpTab[p-2];
        }
        cout << dpTab[inp] << endl;
    }

    return 0;
}
