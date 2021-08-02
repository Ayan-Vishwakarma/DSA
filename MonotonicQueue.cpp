/*
MonotonicQueue [MaximumQueue] : Stores only the highest value based on given < operator.
*/

#include<bits/stdc++.h>
using namespace std;

template <class T,class comp=less<T>>
class MonotonicQueue
{
    private:
    deque<pair<T,int>> deck;
    int n_removed;
    int n_inserted;
    comp compare;
    public:
    MonotonicQueue()
    {
        n_removed = -1;
        n_inserted = -1;
    }
    void insert(T n)
    {
        n_inserted++;
        while(!deck.empty() and (!compare(n,deck.back().first)))
        deck.pop_back();
        deck.push_back(make_pair(n,n _inserted));
    }
    void extract()
    {
        n_removed++;
        if(deck.front().second == n_removed)
        deck.pop_front();
    }
    int size()
    {
        return deck.size();
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
