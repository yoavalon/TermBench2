fn state_change(state: &str) -> &str {
    if state == "idle" {
        "listening"
    } else if state == "listening" {
        "connected"
    } else if state == "connected" {
        "closing"
    } else if state == "closing" {
        "idle"
    } else {
        "error"
    }
}

fn network_protocol() {
    let mut current_state = "idle";
    loop {
        current_state = state_change(current_state);
        println!("{}", current_state);
    }
}

fn main() {
    network_protocol();
}