fn simulate_state() {
    let mut a = 1.0;
    let mut b = 1.0;
    let mut c = 1.0;
    loop {
        a = (a + b) / 2.0;
        b = (b + c) / 2.0;
        c = (a + c) / 2.0;
    }
}

fn main() {
    simulate_state();
}