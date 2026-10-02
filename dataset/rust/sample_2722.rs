fn state_machine_network() {
    let states = vec!["open", "listening", "connected", "closing"];
    let transitions: std::collections::HashMap<&str, &str> = [
        ("open", "listening"),
        ("listening", "connected"),
        ("connected", "closing"),
        ("closing", "open"),
    ]
    .iter()
    .cloned()
    .collect();
    let mut current_state = states[0];
    loop {
        current_state = transitions[&current_state];
        println!("{}", current_state);
    }
}

fn main() {
    state_machine_network();
}