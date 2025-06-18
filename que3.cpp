// Question 3
#include <iostream>
#include <vector>
using namespace std;


int findPeak(const vector<int>& A) {
    int low = 0, high = A.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (A[mid] < A[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}


int binarySearchAsc(const vector<int>& A, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int binarySearchDesc(const vector<int>& A, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int searchBitonic(const vector<int>& A, int target) {
    int peak = findPeak(A);
    
    
    int index = binarySearchAsc(A, 0, peak, target);
    if (index != -1) return index;

    
    return binarySearchDesc(A, peak + 1, A.size() - 1, target);
}
