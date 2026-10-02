extern crate ndarray;

use ndarray::Array1;

fn process_signal(data: &mut Array1<f64>, coeff: f64) {
    for i in 0..data.len() {
        data[i] *= coeff;
    }
}

fn main() {
    let mut data = Array1::from_vec(vec![1.0, 2.0, 3.0, 4.0, 5.0]);
    let coeff = 0.5;
    process_signal(&mut data, coeff);
    println!("{:?}", data);
}