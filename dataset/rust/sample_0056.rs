fn state_machine() {
    let mut state = 0;
    while state < 3 {
        if state == 0 {
            state += 1;
        } else if state == 1 {
            state += 1;
        } else if state == 2 {
            break;
        }
    }
}

fn main() {
    state_machine();
}