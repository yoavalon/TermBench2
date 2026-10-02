fn process_state(state: &str, data: &str) -> (&str, &str) {
    if state == "start" {
        ("connect", data)
    } else if state == "connect" {
        if data == "success" {
            ("data_transfer", data)
        } else {
            ("error", data)
        }
    } else if state == "data_transfer" {
        if data == "complete" {
            ("disconnect", data)
        } else {
            ("data_transfer", data)
        }
    } else if state == "error" {
        ("disconnect", data)
    } else if state == "disconnect" {
        ("end", data)
    } else {
        ("end", data)
    }
}

fn run_network_protocol(data_sequence: Vec<&str>) {
    let mut current_state = "start";
    for data in data_sequence {
        let (new_state, new_data) = process_state(current_state, data);
        current_state = new_state;
        if current_state == "end" {
            break;
        }
    }
}

fn main() {
    run_network_protocol(vec!["success", "complete"]);
}