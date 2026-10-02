fn simulate_thermodynamics() {
    let mut a = 0.5;
    let mut b = 1.0;
    loop {
        let c = a * b;
        a += 0.01;
        b -= 0.01;
    }
}

fn main() {
    simulate_thermodynamics();
}