fn state_machine(state: u32, connections: &mut Vec<u32>) -> u32 {
    if connections.is_empty() {
        return state;
    }
    let next_state = state ^ connections.pop().unwrap();
    state_machine(next_state, connections)
}

fn main() {
    let initial_state = 5;
    let mut connections = vec![1, 2, 4];
    let final_state = state_machine(initial_state, &mut connections);
    println!("{}", final_state);
}