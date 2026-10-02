fn process_data(data: i32, state: &str) -> (&str, f64) {
    if state == "start" {
        if data == 1 {
            ("connected", 1.0)
        } else {
            ("disconnected", 0.0)
        }
    } else if state == "connected" {
        if data == 0 {
            ("disconnected", 0.5)
        } else {
            ("connected", 1.5)
        }
    } else {
        ("error", -1.0)
    }
}

fn main() {
    let state = "start";
    let data_sequence = vec![1, 0, 1, 0, 1];
    let mut result = 0.0;
    let mut current_state = state;

    for &data in &data_sequence {
        let (new_state, value) = process_data(data, current_state);
        current_state = new_state;
        result += value;
    }

    println!("{}", result);
}