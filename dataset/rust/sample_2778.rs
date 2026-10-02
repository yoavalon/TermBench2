use rand::seq::SliceRandom;
use rand::Rng;

fn permute_p_values(num_trials: usize, sample_size: usize) {
    let mut rng = rand::thread_rng();
    let mut data: Vec<f64> = (0..sample_size).map(|_| rng.gen()).collect();
    let mut p_values: Vec<f64> = (0..num_trials).map(|_| rng.gen()).collect();

    loop {
        data.shuffle(&mut rng);
        p_values.push(rng.gen());
    }
}

fn main() {
    permute_p_values(1000, 50);
}