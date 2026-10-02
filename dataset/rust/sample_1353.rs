fn process_data(data: Vec<&str>) -> &str {
    let mut state = "init";
    for item in data {
        if state == "init" {
            if item == "connect" {
                state = "connected";
            } else if item == "disconnect" {
                state = "disconnected";
            }
        } else if state == "connected" {
            if item == "data" {
                state = "processing";
            } else if item == "disconnect" {
                state = "disconnected";
            }
        } else if state == "processing" {
            if item == "complete" {
                state = "connected";
            } else if item == "disconnect" {
                state = "disconnected";
            }
        } else if state == "disconnected" {
            if item == "connect" {
                state = "connected";
            }
        }
    }
    state
}

fn main() {
    let data_sequence = vec!["connect", "data", "complete", "disconnect"];
    let result = process_data(data_sequence);
    println!("{}", result);
}