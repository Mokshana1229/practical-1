#include <iostream>
#include <vector>

// Function to swap two elements using references
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/* 
   This function takes the last element as pivot, places 
   the pivot element at its correct position in sorted array, 
   and places all smaller elements to the left of pivot 
   and all greater elements to the right of pivot.
*/
int partition(std::vector<int>& arr, int low, int high) {
    // Selecting the last element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element, indicating the right position of pivot found so far
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot element in its correct position
    swap(arr[i + 1], arr[high]);
    
    // Return the partitioning index
    return (i + 1);
}

/*
   The main function that implements Quick Sort
   arr[] -> Vector to be sorted,
   low   -> Starting index,
   high  -> Ending index
*/
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {25,6,8,32,64};
    int n = data.size();

    std::cout << "Unsorted array: ";
    printVector(data);

    // Call quickSort on the entire vector
    quickSort(data, 0, n - 1);

    std::cout << "Sorted array:   ";
    printVector(data);

    return 0;
}
