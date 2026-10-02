fn state_machine(state: i32, data: f64) -> (i32, f64) {
    if state == 0 {
        if data < 0.5 {
            (1, data + 0.1)
        } else {
            (2, data - 0.1)
        }
    } else if state == 1 {
        if data < 0.3 {
            (0, data + 0.2)
        } else {
            (2, data - 0.2)
        }
    } else if state == 2 {
        if data > 0.7 {
            (0, data - 0.3)
        } else {
            (1, data + 0.3)
        }
    } else {
        (state, data)
    }
}

fn main() {
    let mut state = 0;
    let mut data = 0.5;
    loop {
        let (new_state, new_data) = state_machine(state, data);
        state = new_state;
        data = new_data;
    }
}