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

class FlippingBitsDiv2 
{
public:
    int getmin(vector <string> S, int M);
    
    string str;
    int group;
    int tn1[2600], tnsum1[2600];
    int tn2[2600], tnsum2[2600];
    
    int dp1[2600][2];
    int dp2[2600][2];
    
    int calcsum(int l, int r)
    {
    	if(l > r) return 0;
    	int tot = tnsum1[r] - tnsum1[l - 1];
    	return tot;
    }
};

int FlippingBitsDiv2::getmin(vector <string> S, int M)
{
    str = "";
    for(int i = 0; i < SIZE(S); i++) str += S[i];
    group = LENGTH(str) / M;
    ZERO(tn1);
    ZERO(tn2);
    
    // init.
    for(int i = 0; i < group; i++)
    {
    	int op = i * M;
    	int ed = op + M;
    	for(int j = op; j < ed; j++)
    	{
    		if(str[j] == '0') tn1[i]++, tn2[group - i - 1]++;
    	}
    	
    	dp1[i][0] = 100000;
    	dp1[i][1] = 100000;
    	dp2[i][0] = 100000;
    	dp2[i][1] = 100000;
    }
    
    // tnsum
    for(int i = 0; i < group; i++)
    {
    	if(i == 0) tnsum1[0] = tn1[0], tnsum2[0] = tn2[0];
    	else
    	{
    		tnsum1[i] = tnsum1[i - 1] + tn1[i];
    		tnsum2[i] = tnsum2[i - 1] + tn2[i];
    	}
    }
    
    // dp.
    for(int i = 0; i <= group; i++)
    {
    	if(i == 0)
    	{
    		dp1[i][0] = dp1[i][1] = dp2[i][0] = dp2[i][1] = 0;
    	}
    	else
    	if(i == 1)
    	{
    		// head -> tail
    		dp1[i][0] = tn1[i - 1];
    		dp1[i][1] = 1 + (M - tn1[i - 1]);
    		
    		// tail -> head
    		dp2[i][0] = tn2[i - 1];
    		dp2[i][1] = 1 + (M - tn2[i - 1]);
    	}
    	else
    	{
    		// head -> tail
    		dp1[i][0] = min(
    			dp1[i - 1][0] + tn1[i - 1],
    			dp1[i - 1][1] + tn1[i - 1]
    		);
    		dp1[i][1] = min(
    			dp1[i - 1][0] + 2 + (M - tn1[i - 1]),
    			dp1[i - 1][1] + (M - tn1[i - 1])
    		);
    		
    		// tail -> head
    		dp2[i][0] = min(
    			dp2[i - 1][0] + tn2[i - 1],
    			dp2[i - 1][1] + tn2[i - 1]
    		);
    		dp2[i][1] = min(
    			dp2[i - 1][0] + 2 + (M - tn2[i - 1]),
    			dp2[i - 1][1] + (M - tn2[i - 1])
    		);
    	}
    }
    
    int minans = 100000000;
    for(int i = 0; i <= group; i++)
    {
    	for(int j = 0; j <= group - i; j++)
    	{
    		int zzl = i;
    		int zzr = group - j - 1;
    		
    		minans = min(minans,
    			min(dp1[i][0], dp1[i][1]) +
    			min(dp2[j][0], dp2[j][1]) +
    			calcsum(zzl, zzr)
    			);
    	}
    }
    
    return minans;
}


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
