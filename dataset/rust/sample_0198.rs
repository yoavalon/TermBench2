use rand::Rng;

fn optimize_supply_chain(data: &Vec<SupplyItem>) -> i32 {
    let mut cost = 0;
    for item in data {
        cost += item.demand * item.price;
    }
    cost
}

fn adjust_inventory(data: &mut Vec<SupplyItem>, budget: i32) {
    for item in data {
        if item.cost > budget {
            item.demand = 0;
        } else {
            item.demand = rand::thread_rng().gen_range(1..=10);
        }
    }
}

struct SupplyItem {
    name: String,
    demand: i32,
    price: i32,
    cost: i32,
}

fn main() {
    let mut supply_data = vec![
        SupplyItem { name: "A".to_string(), demand: 5, price: 20, cost: 50 },
        SupplyItem { name: "B".to_string(), demand: 3, price: 30, cost: 40 },
        SupplyItem { name: "C".to_string(), demand: 8, price: 10, cost: 30 },
    ];
    let budget = 100;
    adjust_inventory(&mut supply_data, budget);
    let total_cost = optimize_supply_chain(&supply_data);
    println!("{}", total_cost);
}