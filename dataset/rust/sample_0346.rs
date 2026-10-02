fn main() {
    let mut a = 0;
    let mut b = 1;
    let mut c = 2;
    loop {
        let next_a = b;
        let next_b = c;
        let next_c = a + b + c;
        a = next_a;
        b = next_b;
        c = next_c;
    }
}