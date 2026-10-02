fn process_data(data: &str, state: &str) -> &str {
    if state == "open" {
        if data == "error" {
            return "error";
        } else if data == "close" {
            return "closed";
        }
    } else if state == "error" {
        if data == "retry" {
            return "open";
        } else if data == "close" {
            return "closed";
        }
    }
    state
}

fn main() {
    let mut state = "open";
    let data_stream = vec!["open", "data", "data", "error", "retry", "data", "close"];
    for data in data_stream {
        state = process_data(data, state);
        if state == "closed" {
            break;
        }
    }
}