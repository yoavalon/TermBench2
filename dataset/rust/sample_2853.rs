fn transition(state: &str, event: &str) -> &'static str {
    if state == "init" && event == "connect" {
        "connected"
    } else if state == "connected" && event == "data" {
        "transmitting"
    } else if state == "transmitting" && event == "disconnect" {
        "disconnected"
    } else {
        state
    }
}

fn sequence() {
    let mut state = "init";
    let events = vec!["connect", "data", "disconnect", "connect", "data", "disconnect"];
    loop {
        for event in &events {
            state = transition(state, event);
            println!("{}", state);
        }
    }
}

fn main() {
    sequence();
}