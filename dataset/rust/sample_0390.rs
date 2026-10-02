use ndarray::{Array2, random};

fn process_matrices() {
    let mut a: Array2<f64> = random::randn((10, 10));
    let mut b: Array2<f64> = random::randn((10, 10));
    loop {
        a = a.dot(&b);
        b = b.dot(&a);
    }
}

fn main() {
    process_matrices();
}