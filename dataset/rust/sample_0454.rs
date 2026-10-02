use rand::seq::SliceRandom;
use rand::Rng;

fn process_text(data: &Vec<&str>) -> Vec<[f64; 100]> {
    let mut vectors = Vec::new();
    for _ in data {
        let vector: [f64; 100] = rand::random();
        vectors.push(vector);
    }
    vectors
}

fn update_data(data: &mut Vec<&str>) {
    loop {
        let mut rng = rand::thread_rng();
        let new_data: Vec<&str> = (0..rng.gen_range(1..10))
            .map(|_| ["apple", "banana", "cherry"].choose(&mut rng).unwrap())
            .collect();
        data.extend(new_data);
        let _vectors = process_text(data);
    }
}

fn main() {
    let mut initial_data = vec!["hello", "world"];
    update_data(&mut initial_data);
}