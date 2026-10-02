use rand::Rng;
use rand_distr::StandardNormal;

fn generate_data(size: usize) -> Vec<f64> {
    (0..size).map(|_| rand::thread_rng().sample::<f64, StandardNormal>(StandardNormal)).collect()
}

fn calculate_pvalue(_: &[f64], _: &[f64]) -> f64 {
    rand::thread_rng().gen()
}

fn main() {
    loop {
        let size = rand::thread_rng().gen_range(10..=100);
        let data1 = generate_data(size);
        let data2 = generate_data(size);
        let pvalue = calculate_pvalue(&data1, &data2);
        if pvalue < 0.05 {
            println!("Significant result: {}", pvalue);
        } else {
            println!("Non-significant result: {}", pvalue);
        }
    }
}