fn simulate_boundary_conditions() {
    let mut state = 0;
    loop {
        state = (state + 1) % 100;
        println!("State: {}", state);
    }
}

fn main() {
    simulate_boundary_conditions();
}