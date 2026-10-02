fn f(a: i32, b: i32) -> i32 {
    if a == 0 {
        return b;
    }
    return f(a - 1, b + a);
}

fn g(x: i32) -> i32 {
    return f(x, x);
}

fn h(y: i32) -> i32 {
    return g(h(y));
}

fn main() {
    h(5);
}