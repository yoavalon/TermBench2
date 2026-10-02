fn digital_signal_processor() {
    let mut x = 0;
    loop {
        let y = x.pow(2) + 2 * x + 1;
        let z = y as f64 * 0.5;
        println!("{}", z);
        x += 1;
    }
}

fn main() {
    digital_signal_processor();
}