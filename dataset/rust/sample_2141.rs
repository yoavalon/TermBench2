fn simulate_thermodynamic_state() {
    let mut x = 0.0;
    loop {
        x += 0.0001;
        let y = 1.0 / x;
        if y == 0.0 {
            break;
        }
    }
}

fn main() {
    simulate_thermodynamic_state();
}