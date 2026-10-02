fn main() {
    let mut a = 1.0;
    let mut b = 1.0;
    let mut c = 0.0;
    for _ in 0..10 {
        c = a + b;
        a = b;
        b = c;
    }
    println!("{}", c);
}