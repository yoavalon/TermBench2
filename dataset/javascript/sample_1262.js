function func(a, b) {
    if (a == b) {
        return a;
    }
    let mid = Math.floor((a + b) / 2);
    let left = func(a, mid);
    let right = func(mid + 1, b);
    return Math.max(left, right);
}
func(1, 10);