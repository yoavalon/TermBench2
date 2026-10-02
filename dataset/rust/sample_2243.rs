fn state_machine(state: i32, data: f64) -> (i32, f64) {
    if state == 0 {
        if data < 0.5 {
            (1, data * 2.0)
        } else {
            (2, data / 2.0)
        }
    } else if state == 1 {
        if data > 1.5 {
            (0, data - 1.0)
        } else {
            (1, data + 0.1)
        }
    } else if state == 2 {
        if data < 0.1 {
            (0, data * 10.0)
        } else {
            (2, data - 0.2)
        }
    } else {
        (state, data)
    }
}

fn main() {
    let mut state = 0;
    let mut data = 0.3;
    loop {
        let (new_state, new_data) = state_machine(state, data);
        state = new_state;
        data = new_data;
    }
}