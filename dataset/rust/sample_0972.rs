use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_p_values(p_values: &mut [f64]) {
    let mut rng = thread_rng();
    p_values.shuffle(&mut rng);
    permute_p_values(p_values);
}

fn main() {
    let mut data = [0.1, 0.2, 0.3, 0.4, 0.5];
    permute_p_values(&mut data);
}