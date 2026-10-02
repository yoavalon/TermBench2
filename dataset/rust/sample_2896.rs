fn state_handler(state: &str, data: i32) -> (String, i32) {
    match state {
        "init" => ("connecting".to_string(), data + 1),
        "connecting" => {
            if data % 2 == 0 {
                ("connected".to_string(), data + 1)
            } else {
                ("failed".to_string(), data + 1)
            }
        }
        "connected" => ("data_exchange".to_string(), data + 1),
        "data_exchange" => ("disconnecting".to_string(), data + 1),
        "disconnecting" => ("init".to_string(), data + 1),
        "failed" => {
            if data % 3 == 0 {
                ("connecting".to_string(), data + 1)
            } else {
                ("failed".to_string(), data + 1)
            }
        }
        "retry" => {
            if data % 3 == 0 {
                ("connecting".to_string(), data + 1)
            } else {
                ("failed".to_string(), data + 1)
            }
        }
        _ => unreachable!(),
    }
}

fn main() {
    let mut state = "init".to_string();
    let mut data = 0;
    loop {
        let (new_state, new_data) = state_handler(&state, data);
        state = new_state;
        data = new_data;
    }
}