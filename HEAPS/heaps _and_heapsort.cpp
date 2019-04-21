// program to implement heaps using arrays and implementing heap sort using arrays 
// overall time complexity of heap sort is 0(n*lg(n))
// time complexity of max_heapify is 0(log(n))
// time complexity of build_max_heapify is 0(n*lg(n))
// @author sourav kumar  , 21-04-2019
#include <iostream>
using namespace std;
// structure for all methods (functions) of heaps 
class heap{
    public:
		// function for creating a max heap where each root node is greater than both of its children
		// so we keep on comparing from each node with given node to locate the best position to restore the heapify property
        void max_heapify(int arr[], int i, int size){
            int left = 2*i + 1;   // in a  heap , left child is always stored at 2*i + 1 considering 0-based array indexing 
            int right = 2*i + 2;  //  similarly for right child , it is 2*i + 2
            int largest = i;      // assuming largest node be itself 
            if(left <= size - 1 && arr[i] < arr[left]){    // comapring with the left node 
                largest = left;
            }   
            if(right <= size - 1 && arr[right] > arr[largest]){   // comapring it with current largest node 
                largest = right;
            }
			// now if largest is not itself, then it is not the best position for a heap and so swap both nodes and call recursivly itself to check further 
            if(largest != i){   
                swap(arr[i], arr[largest]);
                max_heapify(arr, largest, size);
            }
        }
		// function for building a max heap , since subarray a[ n/2+1......n] are leaves and hence we need to start from n/2 where n is the size of heap and restore heapify on each of them
        void build_max_heapify(int arr[], int size){
            for(int i = (size - 1)/2; i >= 0; i--){
                max_heapify(arr, i, size);
            }
        }
		// function for heap sort 
        void heapsort(int arr[], int size){
			// firstly building the max heap from given array 
            build_max_heapify(arr, size);
			// now, going from last node and reducing heap size by 1 each time till 1 node is left and restoring heapify every time to get ascending order sorting 
            for(int i = size - 1; i >= 0; i--){
                swap(arr[0], arr[i]);     // swapping root node with the last node each time 
                max_heapify(arr, 0, i);   // apply heapfy on the remaining reduced heap each time 
            }
        }
};
int main(void){
    heap h;
    int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    h.heapsort(arr, 10);
    for(int i = 0; i <= 9; i++){
        cout << arr[i] << " ";
    }
    // output : 1 2 3 4 7 8 9 10 14 16 

}
