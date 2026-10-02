use rand::Rng;

fn main() {
    let mut data = (0..50).map(|_| rand::thread_rng().gen_range(1..=100)).collect::<Vec<_>>();
    let mut optimized = Vec::new();
    for _ in 0..5 {
        if let Some(&max_val) = data.iter().max() {
            optimized.push(max_val);
            data.retain(|&x| x != max_val);
        }
    }
    println!("{:?}", optimized);
}