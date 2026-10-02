use std::f64;

struct SupplyChain {
    demand: i32,
    supply: i32,
    transport_cost: f64,
    holding_cost: f64,
    inventory: i32,
}

impl SupplyChain {
    fn new(demand: i32, supply: i32, transport_cost: f64, holding_cost: f64) -> SupplyChain {
        SupplyChain {
            demand,
            supply,
            transport_cost,
            holding_cost,
            inventory: supply,
        }
    }

    fn calculate_total_cost(&self, quantity: i32) -> f64 {
        if quantity > self.supply {
            return f64::INFINITY;
        }
        let transport = quantity as f64 * self.transport_cost;
        let holding = self.holding_cost * (self.supply - quantity) as f64 * (self.supply - quantity) as f64;
        transport + holding
    }

    fn optimize_order_quantity(&self) -> i32 {
        let mut min_cost = f64::INFINITY;
        let mut optimal_quantity = 0;
        for quantity in 1..=self.supply {
            let cost = self.calculate_total_cost(quantity);
            if cost < min_cost {
                min_cost = cost;
                optimal_quantity = quantity;
            }
        }
        optimal_quantity
    }
}

fn main() {
    let demand = 100;
    let supply = 150;
    let transport_cost = 2.5;
    let holding_cost = 0.1;
    let supply_chain = SupplyChain::new(demand, supply, transport_cost, holding_cost);
    let optimal_quantity = supply_chain.optimize_order_quantity();
    println!("Optimal Order Quantity: {}", optimal_quantity);
}