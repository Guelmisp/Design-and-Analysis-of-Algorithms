long maxSpam (vector<int> A) {
    
    long max = 0;
    long spam = 0;
    
    vector<int>:: iterator up;
    
    if (A.size() == 1)
        return 1;
    
    for (int i = 0; i < A.size(); i ++) {
        up = upper_bound(A.begin(), A.end(), A[i]);
        spam = ((up - A.begin()) - i);
        if (spam > max)
            max = spam;
    }
    
    return max;
}