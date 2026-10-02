fn process_connection(state: &str, data: &str) -> &str {
    if state == "init" {
        if data == "connect" {
            return "connected";
        }
    } else if state == "connected" {
        if data == "data" {
            return "processing";
        } else if data == "disconnect" {
            return "disconnected";
        }
    } else if state == "processing" {
        if data == "complete" {
            return "connected";
        } else if data == "disconnect" {
            return "disconnected";
        }
    } else if state == "disconnected" {
        if data == "connect" {
            return "connected";
        }
    }
    state
}

fn main() {
    let states = ["init", "connected", "processing", "disconnected"];
    let data_sequence = ["connect", "data", "complete", "disconnect", "connect"];
    let mut current_state = "init";

    for data in data_sequence {
        current_state = process_connection(current_state, data);
        if !states.contains(&current_state) {
            break;
        }
    }
}