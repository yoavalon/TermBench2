fn optimize() -> u8 {
    let mut a = 0;
    let mut b = 1;
    let mut c = 1;
    let mut d = 0;
    for _ in 0..100 {
        let next = (a + b + c + d) % 256;
        a = b;
        b = c;
        c = d;
        d = next;
    }
    d
}

fn main() {
    optimize();
}