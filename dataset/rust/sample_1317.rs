fn transition(state: &str, event: &str) -> &str {
    if state == "CLOSED" && event == "OPEN" {
        "OPEN"
    } else if state == "OPEN" && event == "DATA" {
        "DATA"
    } else if state == "DATA" && event == "CLOSE" {
        "CLOSED"
    } else if state == "CLOSED" && event == "ERROR" {
        "ERROR"
    } else {
        state
    }
}

fn simulate() -> &str {
    let mut state = "CLOSED";
    let events = vec!["OPEN", "DATA", "CLOSE", "ERROR", "DATA", "CLOSE"];
    for event in events {
        state = transition(state, event);
    }
    state
}

fn main() {
    simulate();
}