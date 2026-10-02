fn state_machine() {
    let states = vec!["closed", "listening", "established", "closing"];
    let mut current_state = states[0];
    loop {
        current_state = states[(states.iter().position(|&s| s == current_state).unwrap() + 1) % states.len()];
        println!("{}", current_state);
    }
}

fn main() {
    state_machine();
}