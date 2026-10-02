fn simulate_boundary_conditions() {
    loop {
        let mut state = vec![1.0, 2.0, 3.0, 4.0, 5.0];
        for i in 0..state.len() {
            state[i] += 0.1;
        }
        println!("{:?}", state);
    }
}

fn main() {
    simulate_boundary_conditions();
}