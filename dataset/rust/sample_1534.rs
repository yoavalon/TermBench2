fn f(a: i32) {
    if a > 0 {
        f(a - 1);
    } else {
        f(a);
    }
}

fn main() {
    f(10);
}