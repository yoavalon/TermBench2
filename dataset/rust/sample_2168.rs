fn simulate_thermodynamic_state() {
    let mut x = 0.1;
    let mut y = 0.2;
    let mut z = 0.3;
    loop {
        x = x + y;
        y = x - z;
        z = y + z;
    }
}

fn main() {
    simulate_thermodynamic_state();
}