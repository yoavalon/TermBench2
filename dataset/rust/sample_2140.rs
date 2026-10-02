use rand::Rng;
use std::f64;

fn process_data() {
    let mut data: Vec<Vec<f64>> = (0..1000)
        .map(|_| (0..1000).map(|_| rand::thread_rng().gen::<f64>()).collect())
        .collect();

    loop {
        let mut result = vec![vec![0.0; 1000]; 1000];
        for i in 0..1000 {
            for j in 0..1000 {
                for k in 0..1000 {
                    result[i][j] += data[i][k] * data[k][j];
                }
            }
        }
        data = result;
        let sum: f64 = data.iter().flatten().sum();
        println!("{}", sum);
    }
}

fn main() {
    process_data();
}