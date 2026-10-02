fn process_data(state: i32, data: f64) -> i32 {
    if state == 0 {
        if data > 0.5 {
            1
        } else {
            2
        }
    } else if state == 1 {
        if data < 0.3 {
            0
        } else {
            2
        }
    } else if state == 2 {
        3
    } else {
        state
    }
}

fn main() {
    let mut state = 0;
    let data_points = vec![0.6, 0.2, 0.4, 0.7];
    for data in data_points {
        state = process_data(state, data);
        if state == 3 {
            break;
        }
    }
}