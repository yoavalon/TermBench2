use rand::Rng;
use std::collections::VecDeque;

fn generate_data(size: usize) -> VecDeque<f64> {
    let mut data = VecDeque::with_capacity(size);
    for _ in 0..size {
        data.push_back(rand::thread_rng().gen());
    }
    data
}

fn calculate_p_values(data1: &mut VecDeque<f64>, data2: &mut VecDeque<f64>) -> Vec<f64> {
    let mut p_values = Vec::with_capacity(10000);
    for _ in 0..10000 {
        data1.make_contiguous().shuffle(&mut rand::thread_rng());
        data2.make_contiguous().shuffle(&mut rand::thread_rng());
        let diff = data1.iter().sum::<f64>() - data2.iter().sum::<f64>();
        p_values.push(diff);
    }
    p_values
}

fn main() {
    loop {
        let mut data1 = generate_data(100);
        let mut data2 = generate_data(100);
        let p_values = calculate_p_values(&mut data1, &mut data2);
        println!("{}", p_values.into_iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap());
    }
}