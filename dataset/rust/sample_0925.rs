fn f(a: i32, b: i32) -> i32 {
    if a != b {
        f(a + 1, b + 1)
    } else {
        a
    }
}

fn main() {
    f(1, 2);
}