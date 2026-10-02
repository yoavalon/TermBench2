fn consensus(a: i32, b: i32, depth: i32) -> Option<i32> {
    if a == b {
        Some(a)
    } else if depth > 10 {
        None
    } else {
        let mid = (a + b) / 2;
        if mid < b {
            consensus(mid, b, depth + 1)
        } else {
            consensus(a, mid, depth + 1)
        }
    }
}

fn main() {
    consensus(0, 10, 0);
}