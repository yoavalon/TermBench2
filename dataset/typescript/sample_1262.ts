function func(a: number, b: number): number {
    if (a === b) {
        return a;
    }
    const mid = Math.floor((a + b) / 2);
    const left = func(a, mid);
    const right = func(mid + 1, b);
    return Math.max(left, right);
}

func(1, 10);