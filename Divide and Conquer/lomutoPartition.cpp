int lomutoPartition(vector<int> A, int pivot) {
    int p = pivot;
    int s = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < p) {
            s++;
            int aux = A[s];
            A[s] = A[i];
            A[i] = aux;
        }
    }
    int aux = A[0];
    A[0] = A[s];
    A[s] = aux;
    
    for (int i = 1; i < A.size(); i++) {
        cout << A[i] << " ";

    }
    cout << endl;
    return s+1;
}