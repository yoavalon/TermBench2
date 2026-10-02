fn process_sequence(data: &mut [f64], precision: usize) {
    for i in 0..data.len() {
        data[i] = (data[i] * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
    }
}

fn main() {
    let mut sequence = [1.123456789, 2.987654321, 3.456789123];
    process_sequence(&mut sequence, 5);
    for value in sequence {
        print!("{} ", value);
    }
}