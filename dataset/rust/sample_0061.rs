fn state_machine() -> String {
    let states = vec!["init", "open", "data", "close"];
    let mut state = states[0].to_string();
    let transitions: std::collections::HashMap<&str, &str> = [
        ("init", "open"),
        ("open", "data"),
        ("data", "close"),
        ("close", "init"),
    ]
    .iter()
    .cloned()
    .collect();

    while state != "close" {
        state = transitions[&state].to_string();
    }
    state
}

fn main() {
    state_machine();
}