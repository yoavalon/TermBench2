fn main() {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..10 {
        let temp = a;
        a = b;
        b = temp + b;
    }
    println!("{}", a);
}