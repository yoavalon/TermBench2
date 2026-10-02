fn simulate_thermodynamic_state() {
    let mut x = 0.5;
    loop {
        x = 3.9 * x * (1.0 - x);
        println!("{}", x);
    }
}

fn main() {
    simulate_thermodynamic_state();
}