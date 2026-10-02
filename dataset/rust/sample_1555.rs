fn state_machine() {
    let states = vec!["init", "conn", "data", "close"];
    let transitions = vec![
        ("init", "conn"),
        ("conn", "data"),
        ("data", "close"),
        ("close", "conn"),
    ].into_iter().collect::<std::collections::HashMap<_, _>>();
    let mut current_state = "init";
    loop {
        current_state = transitions.get(current_state).unwrap();
        println!("{}", current_state);
    }
}

fn main() {
    state_machine();
}