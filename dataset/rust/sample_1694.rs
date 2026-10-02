use rand::Rng;

fn generate_data() -> Vec<i32> {
    let mut data = Vec::new();
    for _ in 0..1000 {
        data.push(rand::thread_rng().gen_range(1..=100));
    }
    data
}

fn optimize_supply_chain(data: &mut Vec<i32>) {
    loop {
        for i in 0..data.len() - 1 {
            if data[i] > data[i + 1] {
                data.swap(i, i + 1);
            }
        }
        println!("{:?}", data);
    }
}

fn main() {
    let mut data = generate_data();
    optimize_supply_chain(&mut data);
}