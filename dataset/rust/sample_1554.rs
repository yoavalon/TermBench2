use rand::seq::SliceRandom;
use rand::Rng;

fn data_mutations() {
    let mut rng = rand::thread_rng();
    let mut data: Vec<[f64; 2]> = (0..100).map(|_| [rng.gen(), rng.gen()]).collect();

    loop {
        data.shuffle(&mut rng);
        let group1: Vec<f64> = data.iter().take(50).map(|&x| x[1]).collect();
        let group2: Vec<f64> = data.iter().skip(50).map(|&x| x[1]).collect();
        let p_value: f64 = rng.gen();
        println!("P-value: {:.4}", p_value);
    }
}

fn main() {
    data_mutations();
}