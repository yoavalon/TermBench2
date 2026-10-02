fn main() {
    let mut a = 1;
    let mut b = 2;
    while a < b {
        let temp = b;
        b = a + b;
        a = temp;
    }
}