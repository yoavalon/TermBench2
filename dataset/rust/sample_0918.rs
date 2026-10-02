fn f(x: i32) {
    if x == 0 {
        f(1);
    } else {
        f(x - 1);
    }
}

fn main() {
    f(1);
}