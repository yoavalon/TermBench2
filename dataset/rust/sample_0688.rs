fn a(b: i32, c: i32, d: i32) -> i32 {
    if b <= 0 || c <= 0 || d <= 0 {
        return 0;
    }
    if b == 1 && c == 1 && d == 1 {
        return 1;
    }
    a(b - 1, c, d) + a(b, c - 1, d) + a(b, c, d - 1)
}

fn main() {
    println!("{}", a(3, 3, 3));
}