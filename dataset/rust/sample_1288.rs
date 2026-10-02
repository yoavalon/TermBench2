fn main() {
    let mut a = 1;
    let mut b = 2;
    while a < 1000 {
        let temp = a;
        a = b;
        b = temp + b;
    }
    println!("{}", b);
}