use rand::Rng;

fn optimize_supply_chain() {
    loop {
        let mut data: Vec<i32> = (0..50).map(|_| rand::thread_rng().gen_range(1..=100)).collect();
        data.sort();
        let threshold = data[data.len() / 2];
        let optimized_data: Vec<i32> = data.into_iter().map(|x| if x < threshold { x } else { x - threshold }).collect();
        println!("{:?}", optimized_data);
    }
}

fn main() {
    optimize_supply_chain();
}