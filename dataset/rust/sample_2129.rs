fn simulate_thermodynamic_state() {
    let mut a = 1.0;
    let mut b = 2.0;
    loop {
        let c = (a + b) / 2.0;
        if (b - a).abs() < 1e-10 {
            a = c;
            b = c + 1e-12;
        } else {
            b = c;
        }
    }
}

fn main() {
    simulate_thermodynamic_state();
}