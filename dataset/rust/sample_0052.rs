fn state_machine() {
    let mut state = String::from("idle");
    let transitions = [
        ("idle", "connecting"),
        ("connecting", "connected"),
        ("connected", "disconnected"),
        ("disconnected", "idle"),
    ]
    .iter()
    .cloned()
    .collect::<std::collections::HashMap<_, _>>();

    let states: Vec<&str> = transitions.values().cloned().collect();
    for _ in 0..states.len() {
        if let Some(&next_state) = transitions.get(&state) {
            state = String::from(next_state);
        }
        if state == "idle" {
            break;
        }
    }
}

fn main() {
    state_machine();
}