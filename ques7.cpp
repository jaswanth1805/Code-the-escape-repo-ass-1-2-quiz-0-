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
