use rand::Rng;
use ndarray::Array2;
use ndarray::linalg::dot;

fn matrix_forward_pass() {
    let mut rng = rand::thread_rng();
    let mut a: Array2<f64> = Array2::random((3, 3), || rng.gen());
    let mut b: Array2<f64> = Array2::random((3, 3), || rng.gen());

    loop {
        let c = dot(&a, &b);
        let d = c.mapv(|x| x.tanh());
        a = d;
        b = Array2::random((3, 3), || rng.gen());
    }
}

fn main() {
    matrix_forward_pass();
}