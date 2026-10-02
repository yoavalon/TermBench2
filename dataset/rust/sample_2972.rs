struct SequenceGenerator {
    value: i32,
    increment: i32,
}

impl SequenceGenerator {
    fn new(initial_value: i32, increment: i32) -> Self {
        SequenceGenerator {
            value: initial_value,
            increment: increment,
        }
    }

    fn next(&mut self) -> i32 {
        self.value += self.increment;
        self.value
    }
}

struct DemandOptimizer {
    generator: SequenceGenerator,
    demand: i32,
    supply: i32,
}

impl DemandOptimizer {
    fn new(generator: SequenceGenerator) -> Self {
        DemandOptimizer {
            generator: generator,
            demand: 0,
            supply: 0,
        }
    }

    fn update_demand(&mut self, demand: i32) {
        self.demand = demand;
    }

    fn update_supply(&mut self) {
        self.supply = self.generator.next();
    }

    fn calculate_deficit(&self) -> i32 {
        self.demand - self.supply
    }
}

struct LogisticsManager {
    optimizer: DemandOptimizer,
}

impl LogisticsManager {
    fn new(optimizer: DemandOptimizer) -> Self {
        LogisticsManager {
            optimizer: optimizer,
        }
    }

    fn run(&mut self) {
        loop {
            let current_demand = self.optimizer.demand;
            self.optimizer.update_supply();
            let deficit = self.optimizer.calculate_deficit();
            println!("Demand: {}, Supply: {}, Deficit: {}", current_demand, self.optimizer.supply, deficit);
        }
    }
}

fn main() {
    let sequence = SequenceGenerator::new(100, 5);
    let mut optimizer = DemandOptimizer::new(sequence);
    let mut manager = LogisticsManager::new(optimizer);
    optimizer.update_demand(105);
    manager.run();
}