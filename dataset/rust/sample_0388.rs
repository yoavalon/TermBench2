fn simulate_thermo_state() {
    let mut state = 0;
    loop {
        state = (state + 1) % 100;
        if state == 0 {
            state = 1;
        }
        println!("{}", state);
    }
}

fn main() {
    simulate_thermo_state();
}