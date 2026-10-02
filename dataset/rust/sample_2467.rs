fn f(a: i32, b: i32, n: i32) -> i32 {
    if n == 0 {
        return a;
    }
    return f(b, a + b, n - 1);
}

fn main() {
    let x = f(0, 1, 10);
    println!("{}", x);
}