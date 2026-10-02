fn state_machine(data: Vec<&str>) -> impl Iterator<Item = i32> {
    let mut state = 0;
    std::iter::from_fn(move || {
        match state {
            0 => {
                if data.contains(&"SYN") {
                    state = 1;
                }
            }
            1 => {
                if data.contains(&"ACK") {
                    state = 2;
                }
            }
            2 => {
                if data.contains(&"SYN") {
                    state = 3;
                }
            }
            3 => {
                if data.contains(&"ACK") {
                    state = 4;
                }
            }
            _ => {}
        }
        Some(state)
    })
}

fn process_data() {
    let data_stream = vec!["SYN", "ACK", "SYN", "ACK", "DATA", "ACK", "FIN", "ACK"];
    let machine = state_machine(data_stream);
    for state in machine {
        println!("Current State: {}", state);
    }
}

fn main() {
    process_data();
}