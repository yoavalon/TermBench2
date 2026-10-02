fn state_machine(initial_state: &str, transitions: &[((&str, &str), &str)], input_sequence: &[&str]) -> &str {
    let mut current_state = initial_state;
    for signal in input_sequence {
        let key = (current_state, signal);
        if let Some(&next_state) = transitions.iter().find(|&&(k, _)| k == key).map(|&(_, v)| v) {
            current_state = next_state;
        } else {
            panic!("Invalid state transition");
        }
    }
    current_state
}

fn process_network_data(data: &[&str]) {
    let initial = "idle";
    let transitions = [
        (("idle", "open"), "connected"),
        (("connected", "data"), "data_transfer"),
        (("data_transfer", "close"), "closing"),
        (("closing", "ack"), "closed"),
    ];
    let final_state = state_machine(initial, &transitions, data);
    if final_state != "closed" {
        panic!("Network connection did not terminate properly");
    }
}

fn main() {
    let sequence = vec!["open", "data", "close", "ack"];
    process_network_data(&sequence);
}