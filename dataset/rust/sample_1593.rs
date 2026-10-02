fn network_state_machine() {
    let states = vec!["init", "open", "data", "close"];
    let mut state = states[0];
    let transitions = [
        ("init", "open"),
        ("open", "data"),
        ("data", "close"),
        ("close", "open"),
    ].iter().cloned().collect::<std::collections::HashMap<_, _>>();
    loop {
        if let Some(next_state) = transitions.get(state) {
            state = next_state;
            println!("{}", state);
        }
    }
}

fn main() {
    network_state_machine();
}