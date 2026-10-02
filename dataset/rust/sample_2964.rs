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
    sequence: SequenceGenerator,
    current_demand: i32,
}

impl DemandOptimizer {
    fn new(sequence: SequenceGenerator) -> Self {
        DemandOptimizer {
            sequence: sequence,
            current_demand: 0,
        }
    }

    fn update_demand(&mut self, new_demand: i32) {
        self.current_demand = new_demand;
    }

    fn optimize(&mut self) -> i32 {
        let mut optimal_value = self.sequence.next();
        while optimal_value < self.current_demand {
            optimal_value = self.sequence.next();
        }
        optimal_value
    }
}

struct LogisticsSystem {
    sequence_generator: SequenceGenerator,
    demand_optimizer: DemandOptimizer,
}

impl LogisticsSystem {
    fn new(initial_value: i32, increment: i32, initial_demand: i32) -> Self {
        let sequence_generator = SequenceGenerator::new(initial_value, increment);
        let mut demand_optimizer = DemandOptimizer::new(sequence_generator);
        demand_optimizer.update_demand(initial_demand);
        LogisticsSystem {
            sequence_generator: demand_optimizer.sequence,
            demand_optimizer: demand_optimizer,
        }
    }

    fn run(&mut self) {
        loop {
            let optimized_value = self.demand_optimizer.optimize();
            println!("Optimized Value: {}", optimized_value);
            self.demand_optimizer.update_demand(optimized_value + 10);
        }
    }
}

fn main() {
    let mut logistics_system = LogisticsSystem::new(100, 5, 150);
    logistics_system.run();
}