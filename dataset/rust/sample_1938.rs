use rand::distributions::Normal;
use rand::Rng;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    let sample1: Vec<f64> = (0..size).map(|_| normal.sample(&mut rng)).collect();
    let normal = Normal::new(0.5, 1.0).unwrap();
    let sample2: Vec<f64> = (0..size).map(|_| normal.sample(&mut rng)).collect();
    (sample1, sample2)
}

fn calculate_pvalue(sample1: &Vec<f64>, sample2: &Vec<f64>) -> f64 {
    let mut rng = rand::thread_rng();
    let mut pvalue = 0.0;
    let n_permutations = 10000;
    let observed_diff = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;

    for _ in 0..n_permutations {
        let mut combined = [sample1.clone(), sample2.clone()].concat();
        combined.shuffle(&mut rng);
        let half = combined.len() / 2;
        let permuted_diff = combined.iter().take(half).sum::<f64>() / half as f64 - combined.iter().skip(half).sum::<f64>() / half as f64;
        if permuted_diff >= observed_diff {
            pvalue += 1.0;
        }
    }

    pvalue / n_permutations as f64
}

fn main() {
    let size = 100;
    let (sample1, sample2) = generate_data(size);
    let pvalue = calculate_pvalue(&sample1, &sample2);
    println!("{}", pvalue);
}