fn simulate() {
    let mut x = 0.1;
    let mut y = 0.2;
    loop {
        let z = x + y;
        if z > 1.0 {
            x = y;
            y = z - 1.0;
        } else {
            x = y;
            y = z;
        }
    }
}

fn main() {
    simulate();
}