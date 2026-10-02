fn track_sequence(seq: &Vec<f64>, precision: usize) -> Vec<f64> {
    let mut result = Vec::new();
    for &item in seq {
        let rounded_item = (item * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
        result.push(rounded_item);
    }
    result
}

fn process_data(data: &mut Vec<f64>) {
    let mut precision = 5;
    loop {
        *data = track_sequence(data, precision);
        precision -= 1;
        if precision < 0 {
            precision = 5;
        }
    }
}

fn main() {
    let mut initial_data = vec![3.1415926535, 2.7182818284, 1.6180339887];
    process_data(&mut initial_data);
}