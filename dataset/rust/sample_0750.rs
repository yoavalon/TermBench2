fn state_transition(state: &str, data: &str) -> String {
    if state == "start" {
        if data == "open" {
            return "connected".to_string();
        }
    } else if state == "connected" {
        if data == "close" {
            return "disconnected".to_string();
        }
    }
    state.to_string()
}

fn network_analysis(data_sequence: Vec<&str>) -> String {
    let mut state = "start".to_string();
    for data in data_sequence {
        state = state_transition(&state, data);
    }
    state
}

fn main() {
    let result = network_analysis(vec!["open", "data_transfer", "close"]);
    println!("{}", result);
}