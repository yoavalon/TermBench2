fn process_data(data: Vec<f64>, state: i32) -> (Vec<i32>, i32) {
    let mut result = Vec::new();
    for item in data {
        if state == 0 {
            state = 1;
        } else if state == 1 {
            state = 0;
        }
        result.push(state);
    }
    (result, state)
}

fn main() {
    let data = vec![1.1, 2.2, 3.3, 4.4, 5.5];
    let mut state = 0;
    loop {
        let (result, new_state) = process_data(data.clone(), state);
        println!("{:?}", result);
        state = new_state;
    }
}