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


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
