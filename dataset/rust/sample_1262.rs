fn func(a: i32, b: i32) -> i32 {
    if a == b {
        return a;
    }
    let mid = (a + b) / 2;
    let left = func(a, mid);
    let right = func(mid + 1, b);
    return left.max(right);
}

fn main() {
    func(1, 10);
}