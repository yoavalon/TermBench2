fn process_state(state: i32, data: Vec<i32>) -> (i32, Vec<i32>) {
    if state == 0 {
        if !data.is_empty() {
            (1, data[1..].to_vec())
        } else {
            (2, data)
        }
    } else if state == 1 {
        if !data.is_empty() {
            (0, data[1..].to_vec())
        } else {
            (2, data)
        }
    } else {
        (3, data)
    }
}

fn main() {
    let initial_state = 0;
    let initial_data = vec![1, 0, 1, 0];
    let mut state = initial_state;
    let mut data = initial_data;
    while state < 3 {
        let result = process_state(state, data);
        state = result.0;
        data = result.1;
    }
}