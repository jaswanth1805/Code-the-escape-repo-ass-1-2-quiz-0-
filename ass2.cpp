// Assignment 2 
// Question 1
#include <iostream>
#include <vector>
using namespace std;

int findFirst(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; 
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLast(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1; 
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int countOccurrences(const vector<int>& arr, int target) {
    int first = findFirst(arr, target);
    if (first == -1) return 0; 
    int last = findLast(arr, target);
    return last - first + 1;
}
// Question 2 
#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int>& A) {
    int low = 0, high = A.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (A[mid] > A[high]) {
            low = mid + 1; 
        } else {
            high = mid; 
        }
    }

    return A[low]; 
}
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

// Question 6

int searchMatrix(vector<vector<int>>& A, int B) {
    int N = A.size();
    int M = A[0].size();

    int low = 0, high = N * M - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / M;
        int col = mid % M;

        if (A[row][col] == B)
            return 1;
        else if (A[row][col] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;}

// Question 7
vector<int> computeNiceness(vector<string>& A) {
    int N = A.size();
    vector<int> result(N);
    set<string> seen;

    for (int i = 0; i < N; ++i) {
        result[i] = distance(seen.begin(), seen.lower_bound(A[i]));
        seen.insert(A[i]);
    }

    return result;
}
// Question 8
int getChunkWeight(long long num, int chunkIndex) {
    int weight = 0;
    for (int pos = 0; pos < 5; ++pos) {
        weight += (num % 10) * pow(10, pos);
        num /= 10;
    }
    
    for (int j = 1; j < chunkIndex; ++j) {
        num /= 100000;
    }
    return weight;
}

vector<long long> monkSort(vector<long long> A) {
    int i = 1, N = A.size();
    vector<int> index(N);
    iota(index.begin(), index.end(), 0); 

    while (true) {
        vector<pair<int, int>> weights(N); 
        bool allZero = true;

        for (int j = 0; j < N; ++j) {
            long long num = A[j];
            long long temp = num;
            for (int t = 1; t < i; ++t) temp /= 100000;
            int weight = 0;
            for (int d = 0; d < 5; ++d) {
                weight += (temp % 10) * pow(10, d);
                temp /= 10;
            }
            if (weight != 0) allZero = false;
            weights[j] = {weight, j};
        }

        if (allZero) break;

        stable_sort(A.begin(), A.end(), [&](long long a, long long b) {
            long long ta = a, tb = b;
            for (int t = 1; t < i; ++t) ta /= 100000, tb /= 100000;
            int wa = 0, wb = 0;
            for (int d = 0; d < 5; ++d) {
                wa += (ta % 10) * pow(10, d);
                wb += (tb % 10) * pow(10, d);
                ta /= 10;
                tb /= 10;
            }
            return wa < wb;
        });

        ++i;
    }

    return A;
}

// Question 9

int maxHeightCountDifference(vector<int>& heights) {
    unordered_map<int, int> freq;
    for (int h : heights) {
        freq[h]++;
    }

    int maxDiff = 0;
    for (auto& [h1, c1] : freq) {
        for (auto& [h2, c2] : freq) {
            if (h1 > h2 && c1 > c2) {
                maxDiff = max(maxDiff, c1 - c2);
            }
        }
    }

    return maxDiff;
}
// Question 10
string kthSmallestSuffix(string S, int K) {
    int N = S.length();
    vector<string> suffixes;

    for (int i = 0; i < N; ++i) {
        suffixes.push_back(S.substr(i));
    }

    sort(suffixes.begin(), suffixes.end());

    if (K > 0 && K <= N)
        return suffixes[K - 1];
    else
        return "";
}








