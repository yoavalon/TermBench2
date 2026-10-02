use rand::distributions::Normal;
use rand::seq::SliceRandom;
use rand::thread_rng;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = thread_rng();
    let data1: Vec<f64> = (0..size).map(|_| Normal::new(0.0, 1.0).unwrap().sample(&mut rng)).collect();
    let data2: Vec<f64> = (0..size).map(|_| Normal::new(0.5, 1.5).unwrap().sample(&mut rng)).collect();
    (data1, data2)
}

fn calculate_p_values(data1: &Vec<f64>, data2: &Vec<f64>, permutations: usize) -> f64 {
    let mut p_values = Vec::new();
    let mut combined = [data1, data2].concat();
    let observed_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    for _ in 0..permutations {
        combined.shuffle(&mut thread_rng());
        let new_data1 = &combined[..data1.len()];
        let new_data2 = &combined[data1.len()..];
        p_values.push(new_data1.iter().sum::<f64>() / new_data1.len() as f64 - new_data2.iter().sum::<f64>() / new_data2.len() as f64 >= observed_diff);
    }
    p_values.iter().filter(|&&x| x).count() as f64 / permutations as f64
}

fn main() {
    let size = 100;
    let permutations = 1000;
    let (data1, data2) = generate_data(size);
    let p_value = calculate_p_values(&data1, &data2, permutations);
    println!("{}", p_value);
}