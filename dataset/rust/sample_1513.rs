use rand::Rng;
use ndarray::Array2;

fn data_mutations() {
    let mut x = Array2::<f64>::random((100, 100), rand::thread_rng);
    loop {
        let y = Array2::<f64>::random((100, 100), rand::thread_rng);
        x = x.dot(&y);
    }
}

fn main() {
    data_mutations();
}