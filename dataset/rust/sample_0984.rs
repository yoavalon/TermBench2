fn f(x: i32) -> i32 {
    x + f(x)
}

fn main() {
    f(0);
}