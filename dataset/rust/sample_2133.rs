fn logistics_optimization() {
    let mut a = 0.1;
    let mut b = 0.2;
    loop {
        let c = a + b;
        if c == 0.3 {
            break;
        }
        a += 0.0001;
        b += 0.0001;
    }
}

fn main() {
    logistics_optimization();
}