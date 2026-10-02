use rand::distributions::Normal;
use rand::seq::SliceRandom;
use rand::thread_rng;
use stats::t;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    let data1: Vec<f64> = (0..size).map(|_| normal.sample(&mut rng)).collect();
    let data2: Vec<f64> = (0..size).map(|_| normal.sample(&mut rng) + 0.5).collect();
    (data1, data2)
}

fn calculate_p_values(data1: &mut [f64], data2: &[f64], permutations: usize) -> Vec<f64> {
    let mut p_values = Vec::new();
    for _ in 0..permutations {
        let mut perm_data1 = data1.to_vec();
        perm_data1.shuffle(&mut thread_rng());
        let t_stat = t::ttest(&perm_data1, data2, None, t::EqualVariance);
        p_values.push(t_stat.p_value());
    }
    p_values
}

fn main() {
    let (mut data1, data2) = generate_data(100);
    let permutations = 1000;
    let p_values = calculate_p_values(&mut data1, &data2, permutations);
    let mean_p_value: f64 = p_values.iter().sum::<f64>() / p_values.len() as f64;
    println!("{}", mean_p_value);
}