fn simulate_thermodynamic_states(n: usize) -> Vec<usize> {
    let mut states = Vec::new();
    for i in 0..n {
        let state = i * i + 2 * i + 1;
        states.push(state);
    }
    states
}

fn main() {
    let result = simulate_thermodynamic_states(10);
    println!("{:?}", result);
}