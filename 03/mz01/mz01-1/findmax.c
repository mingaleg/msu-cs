int findmax(const int *a, const int n) {
    int mi = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[mi]) mi = i;
    }
    return mi;
}
