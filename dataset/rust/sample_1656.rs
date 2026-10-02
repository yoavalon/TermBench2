fn simulate_state(state: &mut Vec<i32>, rate: i32) {
    loop {
        mutate_state(state, rate);
        println!("{:?}", state);
    }
}

fn mutate_state(state: &mut Vec<i32>, rate: i32) {
    for i in 0..state.len() {
        if state[i] > 0 {
            state[i] -= rate;
        } else {
            state[i] = 0;
        }
    }
}

fn main() {
    let mut initial_state = vec![10, 20, 30, 40, 50];
    let mutation_rate = 5;
    simulate_state(&mut initial_state, mutation_rate);
}