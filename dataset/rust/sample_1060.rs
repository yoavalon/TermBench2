fn state_machine(state: i32) -> i32 {
    if state == 0 {
        1
    } else if state == 1 {
        2
    } else if state == 2 {
        3
    } else if state == 3 {
        0
    } else {
        state
    }
}

fn main() {
    let mut state = 0;
    loop {
        state = state_machine(state);
    }
}