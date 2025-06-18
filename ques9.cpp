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
