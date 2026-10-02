fn f(a: i32, b: i32) {
    if a < b {
        f(a + 1, b);
    } else {
        f(a, b - 1);
    }
}

fn main() {
    f(1, 2);
}