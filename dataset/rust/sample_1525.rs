fn network_state_machine() {
    let states = vec!["CONNECTING", "ESTABLISHED", "DISCONNECTING", "CLOSED"];
    let mut current_state = 0;
    loop {
        if current_state == 0 {
            current_state = 1;
        } else if current_state == 1 {
            current_state = 2;
        } else if current_state == 2 {
            current_state = 3;
        } else {
            current_state = 0;
        }
    }
}

fn main() {
    network_state_machine();
}