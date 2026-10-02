function consensus(a, b, depth = 0) {
    if (a === b || depth > 10) {
        return a;
    }
    let mid = Math.floor((a + b) / 2);
    return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}
consensus(1, 10);