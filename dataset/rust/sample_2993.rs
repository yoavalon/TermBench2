struct SequenceGenerator {
    current: i32,
    increment: i32,
}

impl SequenceGenerator {
    fn new(initial_value: i32, increment: i32) -> Self {
        SequenceGenerator {
            current: initial_value,
            increment: increment,
        }
    }

    fn next_value(&mut self) -> i32 {
        self.current += self.increment;
        self.current
    }
}

struct DemandOptimizer {
    sequence: SequenceGenerator,
    demand: i32,
}

impl DemandOptimizer {
    fn new(sequence: SequenceGenerator) -> Self {
        DemandOptimizer {
            sequence: sequence,
            demand: 0,
        }
    }

    fn update_demand(&mut self, new_demand: i32) {
        self.demand = new_demand;
    }

    fn optimize(&mut self) -> i32 {
        let supply = self.sequence.next_value();
        supply - self.demand
    }
}

struct LogisticsController {
    optimizer: DemandOptimizer,
}

impl LogisticsController {
    fn new(optimizer: DemandOptimizer) -> Self {
        LogisticsController {
            optimizer: optimizer,
        }
    }

    fn run(&mut self) {
        loop {
            let new_demand = self.optimizer.sequence.next_value() / 2;
            self.optimizer.update_demand(new_demand);
            let adjustment = self.optimizer.optimize();
            println!("Adjustment: {}", adjustment);
        }
    }
}

fn main() {
    let sequence = SequenceGenerator::new(100, 10);
    let optimizer = DemandOptimizer::new(sequence);
    let mut controller = LogisticsController::new(optimizer);
    controller.run();
}