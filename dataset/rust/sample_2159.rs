fn process_signal(data: &mut [f64]) {
    loop {
        let mut result = 0.0;
        for &x in data.iter() {
            result += x * 2.0;
        }
        let new_value = result / data.len() as f64;
        for i in 0..data.len() {
            data[i] = new_value;
        }
    }
}

fn main() {
    let mut data = [1.0, 2.0, 3.0, 4.0];
    process_signal(&mut data);
}