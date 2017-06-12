#inlcude <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


ll n, i, caseNo = 1, order[8];
ld a[8], b[8], timeGap, maxTimeGap; // timeGap is the var temp which calculates the minimum gap expected in the time of flight landing


ld landing(){
  // with the certain landing order and certain time gap;
  // try landing those planes and see what, is the gap to b[order[n-1]];
  ld lastLanding = a[order[0]]; // greedy first aircraft lands immediately;

  for(int i = 1; i < n; i++){
    ld targetLandingTime = lastLanding + timeGap;

    if(targetLandingTime <= b[order[i]]){
      // this aircraft can land, greedily choose max of following;
      lastLanding = max(a[order[i]], targetLanding);
    }else{
      return 1; // return positive value will force binary search to reduce timeGap
    }
  }
  
    // return -ve val will force binary search to increase the timeGap
  return lastLanding - b[order[n-1]];
  
}


int main(){
  while(scanf("%d", &n), n){
    // n <= 2 <= 8

    for(i = 0; i < n; i++){
      scanf("%lf %lf", &a[i], &b[i]);
      // safe landing limits ai and bi;

      timeGap = -1; // start with infeasible solution;
      // can be loop 100 times below;

      while(fabs(lowVal - highVal) >= 1e-3) { // binary search error
	timeGap = (lowVal + highVal) / 2.0;
	ld retVal = greeyLanding(); // round down first
	if(retVal <= le-2){
	  lowVal = timeGap;
	} // must increase timegap
	else{
	  highVal = timeGap;
	}
      }
      maxTimeGap = max
    }
  }
}
