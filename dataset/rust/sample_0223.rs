struct SupplyChainModel {
    capacity: i32,
    demand: i32,
    cost: i32,
    inventory: i32,
    revenue: i32,
    total_cost: i32,
}

impl SupplyChainModel {
    fn new(capacity: i32, demand: i32, cost: i32) -> Self {
        SupplyChainModel {
            capacity,
            demand,
            cost,
            inventory: 0,
            revenue: 0,
            total_cost: 0,
        }
    }

    fn update_inventory(&mut self) {
        if self.demand > self.capacity {
            self.inventory += self.capacity;
        } else {
            self.inventory += self.demand;
        }
    }

    fn calculate_revenue(&mut self) {
        self.revenue = i32::min(self.demand, self.inventory) * self.cost;
    }

    fn calculate_total_cost(&mut self) {
        self.total_cost = self.capacity * self.cost;
    }

    fn optimize(&mut self) -> i32 {
        self.update_inventory();
        self.calculate_revenue();
        self.calculate_total_cost();
        self.revenue - self.total_cost
    }
}

fn run_optimization() -> i32 {
    let capacity = 100;
    let demand = 80;
    let cost = 10;
    let mut model = SupplyChainModel::new(capacity, demand, cost);
    model.optimize()
}

fn main() {
    let profit = run_optimization();
    println!("Optimized Profit: {}", profit);
}