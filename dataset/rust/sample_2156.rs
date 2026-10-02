fn calculate_altitude() {
    let mut a = 30000.0;
    let mut b = 0.0001;
    loop {
        a += b;
        b /= 2.0;
    }
}

fn main() {
    calculate_altitude();
}