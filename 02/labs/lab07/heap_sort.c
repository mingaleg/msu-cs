void siftDown(int *a, int start, int end);

void heap_sort(int n, int *a)
{
    for (int start = (n - 2) / 2; start >=0; --start) {
        siftDown(a, start, n);
    }

    for (int end = n - 1; end > 0; --end) {
        swap(a+end, a);
        siftDown(a, 0, end);
    }
}
 
void siftDown(int *a, int start, int end) {
    int root = start;
    while (root*2 + 1 < end) {
        int child = 2*root + 1;
        if ((child + 1 < end) && CMP(a[child], a[child+1])) {
            ++child;
        }
        if (CMP(a[root], a[child])) {
            swap(a+child, a+root);
            root = child;
        }
        else return;
    }
}
 
