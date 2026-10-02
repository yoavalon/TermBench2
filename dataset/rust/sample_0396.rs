fn network_state_machine() {
    let states = vec!["open", "closed", "listening", "established"];
    let mut current_state = states[0];
    loop {
        if current_state == "open" {
            current_state = states[3];
        } else if current_state == "closed" {
            current_state = states[2];
        } else if current_state == "listening" {
            current_state = states[1];
        } else if current_state == "established" {
            current_state = states[0];
        }
    }
}

fn main() {
    network_state_machine();
}