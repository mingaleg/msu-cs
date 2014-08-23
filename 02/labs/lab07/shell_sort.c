void shell_sort(int n, int * a) {
    //Shell method
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int x = a[i];
            for (int j = i - gap; (j >= 0) && (CMP(x, a[j]) == -1); j -= gap) {
                swap(a+j+gap, a+j);
            }
        }
    }
}
