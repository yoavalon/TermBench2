use rand::Rng;
use rand::seq::SliceRandom;

fn permute(data1: &mut [f64], data2: &mut [f64], n: i32) -> f64 {
    if n == 0 {
        0.0
    } else {
        let mut rng = rand::thread_rng();
        data1.shuffle(&mut rng);
        data2.shuffle(&mut rng);
        let mut combined = [0.0; 200];
        combined[..100].copy_from_slice(data1);
        combined[100..].copy_from_slice(data2);
        combined.shuffle(&mut rng);
        let half = combined.len() / 2;
        let mean_first_half = combined[..half].iter().sum::<f64>() / half as f64;
        let mean_second_half = combined[half..].iter().sum::<f64>() / half as f64;
        mean_first_half - mean_second_half + permute(data1, data2, n - 1)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let mut data1: [f64; 100] = rng.sample_iter(rand_distr::Normal::new(0.0, 1.0).unwrap()).take(100).collect::<Vec<_>>().try_into().unwrap();
    let mut data2: [f64; 100] = rng.sample_iter(rand_distr::Normal::new(0.5, 1.5).unwrap()).take(100).collect::<Vec<_>>().try_into().unwrap();
    let n = 1000;
    let result = permute(&mut data1, &mut data2, n);
    println!("{}", result);
}