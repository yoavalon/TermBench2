fn simulate_thermo_state() -> f64 {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    for _ in 0..1000 {
        x += 0.0001;
        y -= 0.0001;
        z = (x + y) * 10000.0;
    }
    z
}

fn main() {
    simulate_thermo_state();
}