fn transition(state: i32, event: &str) -> i32 {
    if state == 0 {
        if event == "open" { 1 } else { state }
    } else if state == 1 {
        if event == "data" { 2 } else { state }
    } else if state == 2 {
        if event == "close" { 3 } else { state }
    } else {
        0
    }
}

fn simulate() {
    let mut state = 0;
    loop {
        state = transition(state, "open");
        state = transition(state, "data");
        state = transition(state, "close");
    }
}

fn main() {
    simulate();
}