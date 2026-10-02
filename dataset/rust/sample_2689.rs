struct SupplyChainOptimization {
    demand_sequence: Vec<i32>,
    production_capacity: i32,
    inventory: i32,
    backlog: i32,
    total_cost: i32,
    production_plan: Vec<i32>,
}

impl SupplyChainOptimization {
    fn new(demand_sequence: Vec<i32>, production_capacity: i32) -> SupplyChainOptimization {
        SupplyChainOptimization {
            demand_sequence,
            production_capacity,
            inventory: 0,
            backlog: 0,
            total_cost: 0,
            production_plan: Vec::new(),
        }
    }

    fn calculate_production(&mut self, demand: i32) -> i32 {
        if demand > self.production_capacity {
            self.backlog += demand - self.production_capacity;
            self.production_capacity
        } else {
            demand
        }
    }

    fn update_inventory(&mut self, production: i32, demand: i32) {
        self.inventory += production - demand;
    }

    fn update_cost(&mut self, production: i32, demand: i32) {
        if self.backlog > 0 {
            self.total_cost += self.backlog * 10;
        }
        self.total_cost += production * 5;
    }

    fn run_optimization(&mut self) {
        for demand in &self.demand_sequence {
            let production = self.calculate_production(*demand);
            self.production_plan.push(production);
            self.update_inventory(production, *demand);
            self.update_cost(production, *demand);
        }
    }
}

fn main() {
    let demand_sequence = vec![100, 150, 200, 250, 300, 350, 400, 450, 500, 550];
    let production_capacity = 250;
    let mut optimizer = SupplyChainOptimization::new(demand_sequence, production_capacity);
    optimizer.run_optimization();
    println!("Total Cost: {}", optimizer.total_cost);
    println!("Final Inventory: {}", optimizer.inventory);
    println!("Final Backlog: {}", optimizer.backlog);
    println!("Production Plan: {:?}", optimizer.production_plan);
}