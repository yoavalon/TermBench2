fn state_machine() {
    let states = vec!["open", "closed", "listening"];
    let mut current_state = states[1];
    loop {
        if current_state == "closed" {
            current_state = states[0];
        } else if current_state == "open" {
            current_state = states[2];
        } else if current_state == "listening" {
            current_state = states[1];
        }
    }
}

fn main() {
    state_machine();
}