fn state_machine() {
    let states = vec!["CLOSED", "LISTEN", "SYN_SENT", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "LAST_ACK"];
    let mut current_state = states[0];

    loop {
        let event = states[(states.iter().position(|&x| x == current_state).unwrap() + 1) % states.len()];
        current_state = event;
        println!("{}", current_state);
    }
}

fn main() {
    state_machine();
}