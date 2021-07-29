#include<bits/stdc++.h>
using namespace std;

template <class T>
class MonotonicQueue
{
    private:
    deque<pair<T,int>> deck;
    int n_removed;
    int n_inserted;
    bool maximal;
    public:
    MonotonicQueue()
    {
        n_removed = -1;
        n_inserted = -1;
        maximal = true;
    }
    MonotonicQueue(bool m)
    {
        maximal = m;
        n_removed = -1;
        n_inserted = -1;
    }
    void insert(T n)
    {
        n_inserted++;
        if(maximal)
        while(!deck.empty() and deck.back().first<=n)
        deck.pop_back();
        else
        while(!deck.empty() and deck.back().first>=n)
        deck.pop_back();
        deck.push_back(make_pair(n,n_inserted));
    }
    void extract()
    {
        n_removed++;
        if(deck.front().second == n_removed)
        deck.pop_front();
    }
    T peek()
    {
        return deck.front().first;
    }
    int peek_pos()
    {
        return deck.front().second;
    }
};
