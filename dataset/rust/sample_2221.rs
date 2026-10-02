use rand::Rng;
use rand_distr::Normal;

fn process_data(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectors = Vec::new();
    for _ in data {
        let vector: Vec<f64> = (0..100).map(|_| rand::thread_rng().gen()).collect();
        vectors.push(vector);
    }
    vectors
}

fn analyze_vectors(vectors: Vec<Vec<f64>>) {
    loop {
        for vector in vectors.iter_mut() {
            let normal = Normal::new(0.0, 0.01).unwrap();
            for v in vector.iter_mut() {
                *v += normal.sample(&mut rand::thread_rng());
            }
            println!("{}", vector.iter().sum::<f64>() / vector.len() as f64);
        }
    }
}

fn main() {
    let data = vec!["example", "data", "points"];
    let vectors = process_data(data);
    analyze_vectors(vectors);
}