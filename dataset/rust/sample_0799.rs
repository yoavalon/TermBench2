fn state_machine(state: i32, data: &str) -> (i32, &str) {
    if state == 0 {
        if data == "open" {
            (1, "Connection opened")
        } else {
            (0, "Invalid data")
        }
    } else if state == 1 {
        if data == "close" {
            (2, "Connection closed")
        } else {
            (1, "Data ignored")
        }
    } else {
        (2, "Connection already closed")
    }
}

fn process_data(data_sequence: Vec<&str>) -> Vec<&str> {
    let mut state = 0;
    let mut result = Vec::new();
    for data in data_sequence {
        let (new_state, message) = state_machine(state, data);
        state = new_state;
        result.push(message);
    }
    result
}

fn main() {
    let sequence = vec!["open", "send", "close", "send"];
    println!("{:?}", process_data(sequence));
}