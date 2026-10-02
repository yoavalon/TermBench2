use rand::distributions::Normal;
use rand::Rng;

fn simulate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let (t_stat, p_value) = ttest::ttest_ind(sample1, sample2, EqualVar::Assumed);
    p_value
}

fn run_permutations() {
    loop {
        let data1 = simulate_data(100);
        let data2 = simulate_data(100);
        let pvalue = calculate_pvalue(&data1, &data2);
        println!("{}", pvalue);
    }
}

fn main() {
    run_permutations();
}