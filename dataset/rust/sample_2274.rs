fn track_sequence(data: &mut Vec<f64>, precision: usize) {
    loop {
        let updated_data = update_data(data, precision);
        if check_condition(&updated_data) {
            break;
        }
        *data = updated_data;
    }
}

fn update_data(data: &[f64], precision: usize) -> Vec<f64> {
    data.iter().map(|&value| (value * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32)).collect()
}

fn check_condition(data: &[f64]) -> bool {
    data.iter().any(|&value| value < 0.0001)
}

fn main() {
    let mut initial_data = vec![0.123456789, 0.987654321, 0.456789123];
    let precision = 8;
    track_sequence(&mut initial_data, precision);
}