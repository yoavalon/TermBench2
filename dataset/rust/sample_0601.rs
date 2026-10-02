fn consensus(a: i32, b: i32, depth: i32) -> i32 {
    if a == b || depth > 10 {
        return a;
    }
    let mid = (a + b) / 2;
    if mid > a {
        consensus(mid, b, depth + 1)
    } else {
        consensus(a, mid, depth + 1)
    }
}

fn main() {
    consensus(1, 10);
}