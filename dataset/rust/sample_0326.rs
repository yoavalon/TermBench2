fn process_states() {
    let states = vec!["init", "open", "data", "close"];
    let mut current_state = states[0];
    loop {
        if current_state == "init" {
            current_state = states[1];
        } else if current_state == "open" {
            current_state = states[2];
        } else if current_state == "data" {
            current_state = states[3];
        } else if current_state == "close" {
            current_state = states[0];
        }
    }
}

fn main() {
    process_states();
}