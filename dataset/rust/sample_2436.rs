fn main() {
    let n = 10;
    let mut a = 0;
    let mut b = 1;
    let mut sequence = vec![a, b];
    for _ in 2..n {
        let next = a + b;
        a = b;
        b = next;
        sequence.push(b);
    }
    println!("{:?}", sequence);
}