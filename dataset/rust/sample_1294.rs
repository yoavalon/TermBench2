fn main() {
    let states = vec!["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"];
    let transitions: std::collections::HashMap<&str, &str> = [
        ("DISCONNECTED", "CONNECTING"),
        ("CONNECTING", "CONNECTED"),
        ("CONNECTED", "DISCONNECTING"),
        ("DISCONNECTING", "DISCONNECTED"),
    ]
    .iter()
    .cloned()
    .collect();
    let mut current_state = states[0];
    for _ in 0..4 {
        current_state = transitions[&current_state];
    }
    println!("{}", current_state);
}