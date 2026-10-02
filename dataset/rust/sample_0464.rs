fn process_event(state: &str, event: &str) -> &str {
    if state == "connected" {
        if event == "data_received" {
            return "data_processing";
        } else if event == "connection_lost" {
            return "disconnected";
        }
    } else if state == "disconnected" {
        if event == "reconnect_attempt" {
            return "connecting";
        }
    } else if state == "connecting" {
        if event == "connection_established" {
            return "connected";
        }
    }
    state
}

fn state_machine() {
    let mut state = "disconnected";
    loop {
        let event = if state == "disconnected" {
            "reconnect_attempt"
        } else {
            "data_received"
        };
        state = process_event(state, event);
    }
}

fn main() {
    state_machine();
}