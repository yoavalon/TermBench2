fn state_machine() {
    let mut state = 0;
    loop {
        if state == 0 {
            state = 1;
        } else if state == 1 {
            state = 2;
        } else if state == 2 {
            state = 0;
        }
    }
}

fn main() {
    state_machine();
}