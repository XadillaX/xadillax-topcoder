/**
 * The template of Topcoder
 * Author: XadillaX (admin#xcoder.in)
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#define ZERO(x) (memset(x, 0, sizeof(x)))
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define LL long long

/** Segment tree */
#define LC(x) ((x >> 1) + 1)
#define RC(x) ((x >> 1) + 2)

/** Math */
const double pi = acos(-1.0f);
const double eps = 1e-8;

class GearsDiv2 
{
public:
    int getmin(string Directions);
};

int GearsDiv2::getmin(string Directions)
{
    int dp[100][2][2];
    for(int i = 0; i < LENGTH(Directions); i++)
    {
    	if(i == 0)
    	{
    		dp[i][0][0] = 1;
    		dp[i][0][1] = 10000000;
    		dp[i][1][1] = 0;
    		dp[i][1][0] = 10000000;
    	}
    	else
    	if(i == 1)
    	{
    		if(Directions[i] == Directions[i - 1])
    		{
    			dp[i][0][1] = 1;
    			dp[i][1][0] = 1;
    			
    			dp[i][0][0] = 10000000;
    			dp[i][1][1] = 10000000;
    		}
    		else
    		{
    			dp[i][0][0] = 2;
    			dp[i][0][1] = 1;
    			dp[i][1][0] = 1;
    			dp[i][1][1] = 0;
    		}
    	}
    	else
    	if(Directions[i] == Directions[i - 1])
    	{
    		dp[i][1][0] = dp[i - 1][0][0];
    		dp[i][1][1] = dp[i - 1][0][1];
    		
    		dp[i][0][0] = dp[i - 1][1][0] + 1;
    		dp[i][0][1] = dp[i - 1][1][1] + 1;
    	}
    	else
    	{
    		dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][1][0]);
    		dp[i][1][1] = min(dp[i - 1][0][1], dp[i - 1][1][1]);
    		
    		dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][0][0]) + 1;
    		dp[i][0][1] = min(dp[i - 1][1][1], dp[i - 1][1][1]) + 1;
    	}
    	
    	cout << "dp[" << i << "][0][0] = " << dp[i][0][0] << "; ";
    	cout << "dp[" << i << "][1][1] = " << dp[i][1][1] << "; ";
    	cout << "dp[" << i << "][0][1] = " << dp[i][0][1] << "; ";
    	cout << "dp[" << i << "][1][0] = " << dp[i][1][0] << "; ";
    	cout << endl;
    }
    
    int ans;
    int mi = LENGTH(Directions) - 1;
    if(Directions[mi] == Directions[0])
    {
    	ans = min(dp[mi][0][0], min(dp[mi][1][0], dp[mi][0][1]));
    }
    else
    {
    	ans = min(min(dp[mi][0][0], dp[mi][1][1]), min(dp[mi][0][1], dp[mi][1][0]));
    	//ans = min(dp[mi][0][0], min(dp[mi[1][0], min(dp[mi][0][1], dp[mi][1][1])));
    }
    
    return ans;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	GearsDiv2 *obj;
	int answer;
	obj = new GearsDiv2();
	clock_t startTime = clock();
	answer = obj->getmin(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "LRRR";
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "RRR";
	p1 = 2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "LRLR";
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "LRLLRRLLLRRRLLLL";
	p1 = 6;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";
	p1 = 14;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
