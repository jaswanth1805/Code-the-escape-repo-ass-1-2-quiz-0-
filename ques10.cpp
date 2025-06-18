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
