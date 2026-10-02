fn main() {
    let states = vec!["start", "open", "data", "close", "end"];
    let transitions: std::collections::HashMap<&str, &str> = [
        ("start", "open"),
        ("open", "data"),
        ("data", "close"),
        ("close", "end"),
    ]
    .iter()
    .cloned()
    .collect();
    let mut current_state = "start";

    while current_state != "end" {
        if let Some(&next_state) = transitions.get(current_state) {
            current_state = next_state;
        }
    }
}