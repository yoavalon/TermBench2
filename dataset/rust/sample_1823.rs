fn process_data() -> f64 {
    let mut state = 0;
    let mut data = 0.0;
    while state < 3 {
        state += 1;
        if state == 1 {
            data = 1.1 + 2.2;
        } else if state == 2 {
            data = data - 3.3;
        } else {
            data = data * 4.4;
        }
    }
    data
}

fn main() {
    process_data();
}