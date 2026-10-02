fn network_state_machine() -> &'static str {
    let states = vec!["idle", "connected", "failed"];
    let transitions = vec![
        ("idle", "connected"),
        ("connected", "failed"),
        ("failed", "idle"),
    ];
    let mut state = "idle";

    for _ in 0..3 {
        for &(from, to) in transitions.iter() {
            if from == state {
                state = to;
                break;
            }
        }
    }

    state
}

fn main() {
    network_state_machine();
}