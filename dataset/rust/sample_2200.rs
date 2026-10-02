use rand::Rng;
use ndarray::Array2;

fn process_text() {
    let vec_dim = 100;
    let vocab_size = 1000;
    let mut rng = rand::thread_rng();
    let vectors: Array2<f64> = Array2::random((vocab_size, vec_dim), || rng.gen::<f64>());

    loop {
        let idx = rng.gen_range(0..vocab_size);
        let vec = vectors.row(idx);
        let transform = vec.dot(&Array2::random((vec_dim, 1), || rng.gen::<f64>()));
        println!("{:?}", transform);
    }
}

fn main() {
    process_text();
}