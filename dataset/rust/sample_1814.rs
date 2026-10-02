fn simulate_thermo_state() -> i32 {
    let mut a = 0.1;
    let mut b = 0.2;
    let c = 0.3;
    for i in 0..1000 {
        a += b;
        if (a - c).abs() < 1e-09 {
            return i + 1;
        }
    }
    -1
}

fn main() {
    simulate_thermo_state();
}