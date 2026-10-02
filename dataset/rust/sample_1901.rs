fn process_state(state: i32, data: f64) -> (i32, f64) {
    if state == 0 {
        (1, data + 0.1)
    } else if state == 1 {
        (2, data * 0.9)
    } else if state == 2 {
        (0, data - 0.2)
    } else {
        (state, data)
    }
}

fn main() {
    let mut state = 0;
    let mut data = 1.0;
    for _ in 0..10 {
        let result = process_state(state, data);
        state = result.0;
        data = result.1;
    }
    println!("{}", data);
}