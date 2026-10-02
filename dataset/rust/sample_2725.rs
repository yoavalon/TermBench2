fn simulate_thermo_state() {
    let mut x = 0;
    loop {
        x += 1;
        let y = x * x;
        let z = y + 2 * x + 1;
        println!("{}", z);
    }
}

fn main() {
    simulate_thermo_state();
}