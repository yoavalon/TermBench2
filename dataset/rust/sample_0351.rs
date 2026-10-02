fn state_machine() {
    let states = vec!["init", "open", "data", "close"];
    let transitions: std::collections::HashMap<&str, &str> = 
        [("init", "open"), ("open", "data"), ("data", "close"), ("close", "open")]
        .iter().cloned().collect();
    let mut current_state = states[0];
    loop {
        current_state = transitions[&current_state];
    }
}

fn main() {
    state_machine();
}