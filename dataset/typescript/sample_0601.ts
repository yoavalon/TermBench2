function consensus(a: number, b: number, depth: number = 0): number {
    if (a === b || depth > 10) {
        return a;
    }
    const mid = Math.floor((a + b) / 2);
    return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

consensus(1, 10);