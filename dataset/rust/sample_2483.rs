fn sequence(mut a: i32, mut b: i32, n: i32) -> i32 {
    for _ in 0..n {
        let temp = a;
        a = b;
        b = temp + b;
    }
    a
}

fn main() {
    sequence(0, 1, 10);
}