#define LIM 200
int __parent[LIM],__rank[LIM];
void __init__(int n)
{
    for(int i=0;i<n;i++)
    {
        __parent[i] = i;
        __rank[i] = 1;
    }
}
int __find__(int i)
{
    if(i == __parent[i])
    return i;
    return (__parent[i] = __find__(__parent[i]));
}
void __union__(int i,int j)
{
    int pj = __find__(j), pi = __find__(i);
    if(pi == pj)
    {
        return ;
    }
    else if(__rank[pi] > __rank[pj])
    {
        __parent[pj] = pi;
        __rank[pi] += __rank[pj];
    }
    else
    {
        __parent[pi] = pj;
        __rank[pj] += __rank[pi];
    }
}
