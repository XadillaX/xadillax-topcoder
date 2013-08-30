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

class GooseTattarrattatDiv2 
{
public:
    int getmin(string S);
};

int GooseTattarrattatDiv2::getmin(string S)
{
    int maxsame = 0;
    map<char, int> mp;
    for(int i = 0; i < LENGTH(S); i++)
    {
    	mp[S[i]]++;
    	maxsame = max(maxsame, mp[S[i]]);
    }
    
    return LENGTH(S) - maxsame;
}


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
