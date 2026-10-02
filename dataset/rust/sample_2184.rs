fn track_sequence(precision: usize) {
    let mut a = 0.0;
    let mut b = 1.0;
    loop {
        let temp = b;
        b = a + b / precision as f64;
        a = temp;
        println!("{:.precision$}", a, precision = precision);
    }
}

fn main() {
    track_sequence(10);
}