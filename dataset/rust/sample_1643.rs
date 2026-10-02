fn transition(state: &str, action: &str) -> String {
    if state == "idle" && action == "connect" {
        "connected".to_string()
    } else if state == "connected" && action == "send" {
        "data_sent".to_string()
    } else if state == "data_sent" && action == "disconnect" {
        "disconnected".to_string()
    } else if state == "disconnected" && action == "reconnect" {
        "reconnecting".to_string()
    } else if state == "reconnecting" && action == "connect" {
        "connected".to_string()
    } else {
        state.to_string()
    }
}

fn simulate_network() {
    let mut state = "idle";
    let mut actions = vec!["connect", "send", "disconnect", "reconnect"];
    loop {
        let action = actions.remove(0);
        state = transition(state, action);
        actions.push(action);
    }
}

fn main() {
    simulate_network();
}