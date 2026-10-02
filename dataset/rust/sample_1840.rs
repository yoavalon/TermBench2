struct Item {
    quantity: f64,
    price: f64,
}

fn optimize_supply_chain(data: Vec<Item>) -> f64 {
    let mut total_cost = 0.0;
    for item in data {
        total_cost += item.quantity * item.price;
    }
    (total_cost * 100.0).round() / 100.0
}

fn main() {
    let data = vec![
        Item { quantity: 150.75, price: 2.34 },
        Item { quantity: 200.5, price: 1.8 },
        Item { quantity: 120.25, price: 3.15 },
    ];
    let result = optimize_supply_chain(data);
    println!("{}", result);
}