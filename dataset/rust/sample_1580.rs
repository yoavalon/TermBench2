fn state_machine() {
    let states = vec!["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"];
    let mut current_state = 0;
    loop {
        current_state = (current_state + 1) % states.len();
        println!("{}", states[current_state]);
    }
}

fn main() {
    state_machine();
}