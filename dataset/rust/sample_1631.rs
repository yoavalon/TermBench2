fn process_state(state: i32) -> i32 {
    if state == 0 {
        1
    } else if state == 1 {
        2
    } else if state == 2 {
        0
    } else {
        state
    }
}

fn main() {
    let mut current_state = 0;
    loop {
        current_state = process_state(current_state);
        println!("{}", current_state);
    }
}