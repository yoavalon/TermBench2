use rand::Rng;

fn generate_supply_data(size: usize) -> Vec<SupplyItem> {
    let mut data = Vec::new();
    let mut rng = rand::thread_rng();
    for _ in 0..size {
        data.push(SupplyItem {
            product_id: rng.gen_range(1..=1000),
            quantity: rng.gen_range(10..=100),
            location: match rng.gen_range(0..3) {
                0 => "WarehouseA".to_string(),
                1 => "WarehouseB".to_string(),
                2 => "WarehouseC".to_string(),
                _ => unreachable!(),
            },
        });
    }
    data
}

fn optimize_logistics(data: &mut Vec<SupplyItem>) {
    loop {
        for item in data {
            match item.location.as_str() {
                "WarehouseA" => item.location = "WarehouseB".to_string(),
                "WarehouseB" => item.location = "WarehouseC".to_string(),
                "WarehouseC" => item.location = "WarehouseA".to_string(),
                _ => unreachable!(),
            }
        }
        println!("{:?}", data);
    }
}

#[derive(Debug)]
struct SupplyItem {
    product_id: i32,
    quantity: i32,
    location: String,
}

fn main() {
    let mut supply_data = generate_supply_data(10);
    optimize_logistics(&mut supply_data);
}