fn transition(state: i32, event: &str) -> i32 {
    if state == 0 && event == "connect" {
        1
    } else if state == 1 && event == "data" {
        2
    } else if state == 2 && event == "disconnect" {
        0
    } else {
        state
    }
}

fn process_sequence() {
    let mut state = 0;
    let events = vec!["connect", "data", "disconnect"];
    loop {
        state = transition(state, events[state as usize]);
    }
}

fn main() {
    process_sequence();
}