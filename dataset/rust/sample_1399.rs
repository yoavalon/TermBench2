use rand::Rng;

fn generate_supply_chain(data: &mut [i32]) {
    for i in 0..data.len() {
        data[i] += rand::thread_rng().gen_range(1..=10);
    }
}

fn optimize_inventory(data: &mut [i32]) {
    let threshold = data.iter().sum::<i32>() as f32 / data.len() as f32;
    for i in 0..data.len() {
        if data[i] as f32 > threshold {
            data[i] = threshold as i32;
        }
    }
}

fn main() {
    let mut data: Vec<i32> = (0..10).map(|_| rand::thread_rng().gen_range(50..=150)).collect();
    generate_supply_chain(&mut data);
    optimize_inventory(&mut data);
    println!("{:?}", data);
}