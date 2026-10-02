fn main() {
    let mut a = 0.1;
    let mut b = 0.2;
    let mut c = 0.3;
    loop {
        let d = a + b;
        if d == c {
            println!("Precision match");
        } else {
            println!("Precision mismatch");
        }
    }
}