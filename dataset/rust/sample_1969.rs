fn state_transition(state: &str, data: f64) -> String {
    match state {
        "start" => {
            if data > 0.5 {
                "active".to_string()
            } else {
                "idle".to_string()
            }
        }
        "active" => {
            if data < 0.5 {
                "idle".to_string()
            } else {
                "closing".to_string()
            }
        }
        "idle" => {
            if data > 0.5 {
                "active".to_string()
            } else {
                "idle".to_string()
            }
        }
        "closing" => "terminated".to_string(),
        _ => state.to_string(),
    }
}

fn network_monitor(data_points: &[f64]) -> String {
    let mut state = "start";
    for &data in data_points {
        state = &state_transition(state, data);
        if state == "terminated" {
            break;
        }
    }
    state.to_string()
}

fn main() {
    let data_sequence = vec![0.6, 0.7, 0.4, 0.3, 0.8];
    let result = network_monitor(&data_sequence);
    println!("{}", result);
}