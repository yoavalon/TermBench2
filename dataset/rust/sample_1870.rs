fn state_machine_network_connection() -> i32 {
    let mut state = 0;
    while state < 3 {
        if state == 0 {
            state += 1;
        } else if state == 1 {
            state += 1;
        } else if state == 2 {
            state += 1;
        }
    }
    state
}

fn main() {
    state_machine_network_connection();
}