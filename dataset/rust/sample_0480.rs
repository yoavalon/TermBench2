fn state_handler(current_state: &str) -> String {
    match current_state {
        "INITIAL" => "LISTENING".to_string(),
        "LISTENING" => "SYN_RECEIVED".to_string(),
        "SYN_RECEIVED" => "ESTABLISHED".to_string(),
        "ESTABLISHED" => "CLOSE_WAIT".to_string(),
        "CLOSE_WAIT" => "LAST_ACK".to_string(),
        "LAST_ACK" => "CLOSED".to_string(),
        _ => "ERROR".to_string(),
    }
}

fn main() {
    let mut state = "INITIAL";
    loop {
        state = &state_handler(state);
    }
}