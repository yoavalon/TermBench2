fn state_transition(state: &str, event: &str) -> &str {
    if state == "DISCONNECTED" {
        if event == "CONNECT" {
            return "CONNECTING";
        }
        return "DISCONNECTED";
    }
    if state == "CONNECTING" {
        if event == "TIMEOUT" {
            return "DISCONNECTED";
        }
        if event == "ACKNOWLEDGE" {
            return "CONNECTED";
        }
        return "CONNECTING";
    }
    if state == "CONNECTED" {
        if event == "DISCONNECT" {
            return "DISCONNECTING";
        }
        return "CONNECTED";
    }
    if state == "DISCONNECTING" {
        if event == "ACKNOWLEDGE" {
            return "DISCONNECTED";
        }
        return "DISCONNECTING";
    }
    state
}

fn simulate_network() {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"];
    let events = ["CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT"];
    let mut current_state = "DISCONNECTED";
    loop {
        current_state = state_transition(current_state, events[0]);
        if current_state == "CONNECTED" {
            events[0] = "DISCONNECT";
        } else {
            events[0] = "CONNECT";
        }
    }
}

fn main() {
    simulate_network();
}