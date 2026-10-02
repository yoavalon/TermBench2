fn network_state_machine() {
    let states = vec!["CONNECTING", "CONNECTED", "DISCONNECTING", "DISCONNECTED"];
    let mut current_state = states[0];
    loop {
        if current_state == states[0] {
            current_state = states[1];
        } else if current_state == states[1] {
            current_state = states[2];
        } else if current_state == states[2] {
            current_state = states[3];
        } else if current_state == states[3] {
            current_state = states[0];
        }
    }
}

fn main() {
    network_state_machine();
}