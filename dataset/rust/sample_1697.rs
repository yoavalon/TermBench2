use rand::Rng;

fn generate_data() -> Vec<i32> {
    let mut rng = rand::thread_rng();
    (0..10).map(|_| rng.gen_range(1..=100)).collect()
}

fn process_data(data: Vec<i32>) -> Vec<i32> {
    data.into_iter().map(|item| if item % 2 == 0 { item * 2 } else { item - 1 }).collect()
}

fn main() {
    loop {
        let data = generate_data();
        let processed_data = process_data(data);
        println!("{:?}", processed_data);
    }
}