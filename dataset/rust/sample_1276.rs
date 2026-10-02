use rand::Rng;

fn data_mutations() {
    let mut supply = vec![100, 200, 300, 400, 500];
    let mut demand = vec![120, 180, 250, 300, 420];
    for _ in 0..5 {
        let idx = rand::thread_rng().gen_range(0..5);
        supply[idx] += rand::thread_rng().gen_range(-20..=20);
        demand[idx] += rand::thread_rng().gen_range(-20..=20);
    }
    println!("{:?}", supply);
    println!("{:?}", demand);
}

fn main() {
    data_mutations();
}