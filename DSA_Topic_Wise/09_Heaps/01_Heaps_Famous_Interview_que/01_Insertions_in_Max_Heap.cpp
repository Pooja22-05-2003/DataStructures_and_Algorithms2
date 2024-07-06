https://ideone.com/5d1jNe

// In the heap implementation , we will not anything on the 
    // 0th index
    // if the heap has 6 nodes then create 7 length array
    
/*
 FORMULA:
 
1. If the Parent node is present at the ith index,then its

LeftChild= (2*i)index
RightChild= (2*i+1)
For any nodes, its parent index will be (i/2).

    
*/

// Ist Operation is ISERTION
// Que: Insert value=55 in the heap.

// STEPS:
/*
1. Insert the element at the end if the array.
2. Take the element currently inserted to its correct position.
How to do that??

-> current element ko uske parent se compare karo, parent big hona chahiye.
-> If the condition is not satisfying than swap the 2 elements.
-> Now again check this for the swapped element, whenever the condition become true, then stop there only.

*/
#include <bits/stdc++.h>

using namespace std;
class heap{
    public:
    int arr[1000];
    int size;
    
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    
    void insert(int val)
    {
        size++;
        int ind=size;
        arr[ind]=val;
        
        // move the current element to its correct place in the heap.
        while(ind>1)
        {
            int parent=ind/2;
            
            if(arr[parent]<arr[ind])
            {
                // ind element is at its incorrect place, swap it with the parent.
                swap(arr[parent],arr[ind]);
                ind=parent;// now put the parent element to its correct place.
            }
            else
            {
                return;// it means now our heap is correct and all the elements are at its correct position after the insertion.
            }
        }
        
        
    }
    
    void print()
    {
        cout<<"Printing array elements:"<<endl;
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print(); 
    /*
    output:
    Printing array elements:
    55 54 53 50 52 
    
    */
    return 0;
}