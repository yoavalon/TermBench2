fn main() {
    let mut a = 1.0;
    loop {
        let b = a + 0.1;
        if b == a {
            break;
        }
        a = b;
    }
}