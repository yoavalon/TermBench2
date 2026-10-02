use rand::Rng;

fn optimize_supply_chain(data: &mut Vec<SupplyItem>) {
    for _ in 0..10 {
        for item in data.iter_mut() {
            item.cost = rand::thread_rng().gen_range(0.5..=2.0) * item.cost;
            item.delay = rand::thread_rng().gen_range(0..=5);
        }
    }
}

struct SupplyItem {
    id: i32,
    cost: f64,
    delay: i32,
}

fn main() {
    let mut data = vec![
        SupplyItem { id: 1, cost: 100.0, delay: 2 },
        SupplyItem { id: 2, cost: 150.0, delay: 3 },
    ];
    optimize_supply_chain(&mut data);
    println!("{:?}", data);
}