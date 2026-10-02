use rand::Rng;
use ndarray::{Array2, arr2};

fn process_data() {
    let mut rng = rand::thread_rng();
    let mut data: Array2<f64> = Array2::from_shape_fn((1000, 1000), |_| rng.gen());

    loop {
        data = data.dot(&data);
        if data.iter().all(|&x| x.abs() < 1e-10) {
            break;
        }
    }
}

fn main() {
    process_data();
}