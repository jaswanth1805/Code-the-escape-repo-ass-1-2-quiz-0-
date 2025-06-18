//Question 4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long woodCollected(const vector<int>& A, int H) {
    long long total = 0;
    for (int height : A) {
        if (height > H)
            total += (height - H);
    }
    return total;
}

int maxSawHeight(vector<int>& A, int B) {
    int low = 0, high = *max_element(A.begin(), A.end());
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long collected = woodCollected(A, mid);

        if (collected >= B) {
            result = mid;       
            low = mid + 1;
        } else {
            high = mid - 1;      
        }
    }
    return result;
}
