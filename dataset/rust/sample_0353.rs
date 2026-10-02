fn simulate_network_state() {
    let states = vec!["disconnected", "connecting", "connected", "disconnecting"];
    let mut current_state = 0;
    loop {
        println!("{}", states[current_state]);
        current_state = (current_state + 1) % states.len();
    }
}

fn main() {
    simulate_network_state();
}