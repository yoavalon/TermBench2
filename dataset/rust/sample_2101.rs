fn simulate_thermodynamic_state() {
    let mut a = 1.0;
    let mut b = 2.0;
    loop {
        let temp = b;
        b = a / b + 1e-10;
        a = temp;
    }
}

fn main() {
    simulate_thermodynamic_state();
}