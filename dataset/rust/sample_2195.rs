fn process_data(mut x: f64) {
    loop {
        x = x * 2.0;
        if x > 10000000000.0 {
            x = x / 10000000000.0;
        }
    }
}

fn main() {
    process_data(0.1);
}