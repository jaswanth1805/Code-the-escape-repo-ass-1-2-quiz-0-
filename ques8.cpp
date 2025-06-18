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
