//Question 5

int searchInsert(const vector<int>& A, int B) {
    int low = 0, high = A.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
