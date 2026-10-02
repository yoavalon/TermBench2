fn process_connections(states: Vec<&str>, transitions: std::collections::HashMap<&str, &str>, start: &str, end: &str) -> bool {
    let mut current = start;
    for _ in 0..(states.len() * 2) {
        if current == end {
            break;
        }
        current = transitions.get(current).unwrap_or(&current);
    }
    current == end
}

fn main() {
    let states = vec!["A", "B", "C"];
    let mut transitions = std::collections::HashMap::new();
    transitions.insert("A", "B");
    transitions.insert("B", "C");
    transitions.insert("C", "A");
    let start = "A";
    let end = "C";
    println!("{}", process_connections(states, transitions, start, end));
}