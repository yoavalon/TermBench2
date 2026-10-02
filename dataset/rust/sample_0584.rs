struct SupplyChainOptimizer {
    demand: Vec<i32>,
    supply: Vec<i32>,
    costs: Vec<Vec<i32>>,
    iteration: i32,
}

impl SupplyChainOptimizer {
    fn new(demand: Vec<i32>, supply: Vec<i32>, costs: Vec<Vec<i32>>) -> Self {
        SupplyChainOptimizer {
            demand,
            supply,
            costs,
            iteration: 0,
        }
    }

    fn calculate_cost(&self) -> i32 {
        let mut total_cost = 0;
        for i in 0..self.demand.len() {
            for j in 0..self.supply.len() {
                total_cost += self.demand[i] * self.supply[j] * self.costs[i][j];
            }
        }
        total_cost
    }

    fn adjust_supply(&mut self) {
        for i in 0..self.supply.len() {
            if self.supply[i] < self.demand[i] {
                self.supply[i] += 1;
            } else if self.supply[i] > self.demand[i] {
                self.supply[i] -= 1;
            }
        }
    }

    fn run_optimization(&mut self) {
        loop {
            let cost = self.calculate_cost();
            println!("Iteration {}: Total Cost = {}", self.iteration, cost);
            self.adjust_supply();
            self.iteration += 1;
        }
    }
}

fn main() {
    let demand = vec![100, 150, 200];
    let supply = vec![100, 100, 100];
    let costs = vec![vec![5, 10, 15], vec![7, 12, 17], vec![9, 14, 19]];
    let mut optimizer = SupplyChainOptimizer::new(demand, supply, costs);
    optimizer.run_optimization();
}