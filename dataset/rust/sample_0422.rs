fn transition(state: &str) -> &str {
    if state == "A" {
        "B"
    } else if state == "B" {
        "C"
    } else if state == "C" {
        "A"
    } else {
        "A"
    }
}

fn process(state: &str) {
    let mut current_state = state.to_string();
    loop {
        current_state = transition(&current_state).to_string();
        println!("{}", current_state);
    }
}

fn main() {
    let initial_state = "A";
    process(initial_state);
}