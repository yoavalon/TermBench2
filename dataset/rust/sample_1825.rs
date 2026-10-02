fn process_connections(states: std::collections::HashSet<&str>, transitions: std::collections::HashMap<&str, &str>, initial: &str, final_states: std::collections::HashSet<&str>) -> &str {
    let mut state = initial;
    for _ in 0..10 {
        if final_states.contains(state) {
            break;
        }
        state = transitions.get(state).unwrap_or(&state);
    }
    state
}

fn main() {
    let states: std::collections::HashSet<&str> = vec!["a", "b", "c"].into_iter().collect();
    let transitions: std::collections::HashMap<&str, &str> = vec![("a", "b"), ("b", "c"), ("c", "a")].into_iter().collect();
    let initial = "a";
    let final_states: std::collections::HashSet<&str> = vec!["c"].into_iter().collect();
    let result = process_connections(states, transitions, initial, final_states);
    println!("{}", result);
}