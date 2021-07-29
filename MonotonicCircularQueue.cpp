template <class T,int N>
class MonotonicCircularQueue
{
    private:
    pair<T,int> *arr;
    int front,back;
    int n_inserted,n_removed;
    bool maximal;
    public:
    MonotonicCircularQueue()
    {
        arr = malloc(sizeof(T) * N);
        front = back = n_inserted = n_removed = -1;
        maximal = true;
    }
    MonotonicCircularQueue(bool m)
    {
        arr = malloc(sizeof(T) * N);
        front = back = n_inserted = n_removed = -1;
        maximal = m;
    }
    void insert(T n)
    {   n_inserted++;
        if(front == -1)
        {
            front = back = 0;
            arr[0] = make_pair(n,n_inserted);
        }
        else if(maximal)
        {
            while(back!=front and arr[back].first <= n)
            {back--;
            if(back==-1)
            back = N-1;
            }
            if(back==front and arr[back].first<=n)
            {   front = back = 0;
                arr[0] = make_pair(n,n_inserted);
            }
            else 
            {
                back++;
                if(back==N)
                back = 0;
                arr[back] = make_pair(n,n_inserted);
            }
        }
        else 
        {
            while(back!=front and arr[back].first >= n)
            {back--;
            if(back==-1)
            back = N-1;
            }
            if(back==front and arr[back].first>=n)
            {   front = back = 0;
                arr[0] = make_pair(n,n_inserted);
            }
            else 
            {
                back++;
                if(back==N)
                back = 0;
                arr[back] = make_pair(n,n_inserted);
            }
        }
    }
    void extract()
    {   n_removed++;
        if(front!=-1 and arr[front].second == n_removed)
        {
            if(front == back)
            front = back = -1;
            else
            {
                front++;
                if(front==N)
                front = 0;
            }
        }
    }
    T peep()
    {
        return arr[front].first;
    }
};
