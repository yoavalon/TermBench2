fn analyze_network_connections(connections: Vec<&str>, states: Vec<&str>, transitions: Vec<(&str, &str, &str)>) -> &str {
    let mut current_state = states[0];
    for connection in connections {
        for transition in &transitions {
            if transition.0 == current_state && transition.1 == connection {
                current_state = transition.2;
                break;
            }
        }
    }
    current_state
}

fn main() {
    let connections = vec!["open", "data", "close"];
    let states = vec!["idle", "active", "closed"];
    let transitions = vec![
        ("idle", "open", "active"),
        ("active", "data", "active"),
        ("active", "close", "closed"),
    ];
    let result = analyze_network_connections(connections, states, transitions);
    println!("{}", result);
}