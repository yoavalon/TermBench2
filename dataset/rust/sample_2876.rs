fn state_transition(state: i32, data: i32) -> i32 {
    if state == 0 {
        if data == 1 {
            1
        } else {
            0
        }
    } else if state == 1 {
        if data == 2 {
            2
        } else {
            1
        }
    } else if state == 2 {
        if data == 3 {
            0
        } else {
            2
        }
    } else {
        state
    }
}

fn process_data(sequence: &[i32]) {
    let mut state = 0;
    loop {
        for &data in sequence {
            state = state_transition(state, data);
        }
    }
}

fn main() {
    let sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3];
    process_data(&sequence);
}