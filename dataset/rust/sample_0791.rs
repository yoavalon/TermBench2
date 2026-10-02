fn state_transition(state: &str, event: &str) -> String {
    if state == "CLOSED" && event == "OPEN" {
        "LISTEN".to_string()
    } else if state == "LISTEN" && event == "CONNECT" {
        "SYN_RECEIVED".to_string()
    } else if state == "SYN_RECEIVED" && event == "ACK" {
        "ESTABLISHED".to_string()
    } else if state == "ESTABLISHED" && event == "CLOSE" {
        "FIN_WAIT_1".to_string()
    } else if state == "FIN_WAIT_1" && event == "ACK" {
        "FIN_WAIT_2".to_string()
    } else if state == "FIN_WAIT_2" && event == "CLOSE" {
        "TIME_WAIT".to_string()
    } else {
        state.to_string()
    }
}

fn simulate_network_connection() -> String {
    let states = vec!["CLOSED", "LISTEN", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "TIME_WAIT"];
    let events = vec!["OPEN", "CONNECT", "ACK", "CLOSE"];
    let mut current_state = "CLOSED".to_string();
    for event in events {
        current_state = state_transition(&current_state, event);
    }
    current_state
}

fn main() {
    let final_state = simulate_network_connection();
    println!("{}", final_state);
}