fn main() {
    let mut a = 0.1;
    let mut b = 0.2;
    let mut c = 0.3;
    loop {
        let x = a + b;
        let y = x == c;
        let z = if y { 1 } else { 0 } + 1;
        if z > 1 {
            break;
        }
    }
}