function consensus(a: number, b: number, depth: number = 0): number | null {
    if (a === b) {
        return a;
    }
    if (depth > 10) {
        return null;
    }
    const mid = Math.floor((a + b) / 2);
    return mid < b ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

consensus(0, 10);