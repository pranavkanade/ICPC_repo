#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

vll primes;
int inp;
int m = 0;
void atkin(ll limit)
{
    if (limit > 2)  primes.push_back(2);
    if (limit > 3)  primes.push_back(3);

    bool sieve[limit];
    for (ll i=0; i<limit; i++)
        sieve[i] = false;

    for (ll x = 1; x*x < limit; x++)
    {
        for (ll y = 1; y*y < limit; y++)
        {
            ll n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    for (ll r = 5; r*r < limit; r++)
    {
        if (sieve[r])
        {
            for (ll i = r*r; i < limit; i += r*r)
                sieve[i] = false;
        }
    }
    for (ll a = 5; a < limit; a++)
        if (sieve[a])
            primes.push_back(a);
}

void rec(vll arr, int count, int ind, vll result){

    count++;
    result.push_back(arr[ind]);
    arr.erase(arr.begin() + ind);
    if(count == inp && binary_search(primes.begin(), primes.end(), (result[count -1 ] + 1))
       && binary_search(primes.begin(), primes.end(), (result[result.size() - 1] + result[result.size() - 2]))){
        m++;
        for(int i = 0; i < count; i++){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    if(count != 1 && binary_search(primes.begin(), primes.end(), (result[result.size() - 1] + result[result.size() - 2]))){
        for(int i = 0; i < arr.size(); i++){
            rec(arr, count, i, result);
        }
    }
    else if (count == 1){
        for(int i = 0; i < arr.size(); i++){
            rec(arr, count, i, result);
        }
    }
}


int main() {

    cin >> inp;

    atkin(2*inp);

    vll arr(inp);
    vll result;
    for(int i = 0; i < inp; i++){
        arr[i] = i+1;
    }

    int count = 0;

    rec(arr, count, 0, result);
    cout << m << endl;
    return 0;
}