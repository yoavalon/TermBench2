fn process() {
    let states = vec!["init", "connect", "data_exchange", "disconnect", "done"];
    let transitions: std::collections::HashMap<&str, &str> = [
        ("init", "connect"),
        ("connect", "data_exchange"),
        ("data_exchange", "disconnect"),
        ("disconnect", "done"),
    ]
    .iter()
    .cloned()
    .collect();
    let mut current_state = states[0];
    while current_state != states[states.len() - 1] {
        if let Some(&next_state) = transitions.get(current_state) {
            current_state = next_state;
        }
    }
    println!("Process terminated");
}

fn main() {
    process();
}