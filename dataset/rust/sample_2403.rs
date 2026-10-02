fn sequence(a: i32, b: i32, n: i32) -> i32 {
    if n == 0 {
        a
    } else if n == 1 {
        b
    } else {
        sequence(b, a + b, n - 1)
    }
}

fn main() {
    let a = 0;
    let b = 1;
    let n = 10;
    let result = sequence(a, b, n);
    println!("{}", result);
}