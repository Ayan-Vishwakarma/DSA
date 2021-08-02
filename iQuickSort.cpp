/*
QuickSorting for associated pair of arrays/vectors/deques where association between elements of the two containers
should be maintained,for example,if A and B be two linear-containers of equal size such that A[i] -> B[i] {A[i] maps to B[i]},then 
swapping A[i] with A[j] implies automatic swapping of B[i] with B[j] because A[i] maps to B[i] and A[j] maps to B[j].

This is a convenience function {useful for leetcode} and the same effect can be mimicked by using vector<pair<T,T>> and using sort method.
*/

#include<bits/stdc++.h>
using namespace std;

//_____________________________________________________________
//_____________________ARRAY-FORMAT____________________________
//_____________________________________________________________
template<class T>
void iQuickSort(T* array,T* index,int N)
{
    quicksort_procedure<T>(0,N-1,array,index);
}
template<class T>
void quicksort_procedure(int l,int r,T* array,T* index)
{ 
    if(l>=r)
    return;
    int key = array[l];
    int l1 = l+1,r1 = r;
    while(l1<=r and array[l1]<=key)
    l1++;
    if(l1==r+1)
    {
        swap(array[l],array[r]);
        swap(index[l],index[r]);
        quicksort_procedure<T>(l,r-1,array,index);
        return ;
    }
    label1:
    while(array[l1]<=key)
    l1++;
    while(array[r1]>key)
    r1--;
    if(r1+1==l1)
    goto label2;
    swap(array[l1],array[r1]);
    swap(index[l1],index[r1]);
    goto label1;
    label2:
    swap(array[l],array[r1]);
    swap(index[l],index[r1]);
        quicksort_procedure<T>(l,r1-1,array,index);
        quicksort_procedure<T>(l1,r,array,index);
        return ;
}
//____________________________________________________________
//_____________________VECTOR-FORMAT__________________________
//____________________________________________________________
template<class T>
void iQuickSort(T& array,T& index)
{
quicksort_procedure<T>(0,array.size()-1,array,index);
}
template<class T>
void quicksort_procedure(int l,int r,T& array,T& index)
{ 
if(l>=r)
return;
int key = array[l];
int l1 = l+1,r1 = r;
while(l1<=r and array[l1]<=key)
l1++;
if(l1==r+1)
{
    swap(array[l],array[r]);
    swap(index[l],index[r]);
    quicksort_procedure(l,r-1,array,index);
    return ;
}
label1:
while(array[l1]<=key)
l1++;
while(array[r1]>key)
r1--;
if(r1+1==l1)
goto label2;
swap(array[l1],array[r1]);
swap(index[l1],index[r1]);
goto label1;
label2:
swap(array[l],array[r1]);
swap(index[l],index[r1]);
quicksort_procedure(l,r1-1,array,index);
quicksort_procedure(l1,r,array,index);
return ;
}
