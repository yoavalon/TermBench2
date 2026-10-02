fn f(a: i32, b: i32, c: i32) -> i32 {
    if a > b {
        c
    } else {
        f(a + 1, b, c + 1)
    }
}

fn main() {
    let result = f(1, 10, 0);
    println!("{}", result);
}