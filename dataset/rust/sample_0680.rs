fn consensus(a: i32, b: i32) -> i32 {
    if a == b {
        a
    } else if a > b {
        consensus(a - 1, b)
    } else {
        consensus(a, b - 1)
    }
}

fn main() {
    consensus(10, 15);
}