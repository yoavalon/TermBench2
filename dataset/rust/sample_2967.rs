struct SequenceGenerator {
    state: i32,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator { state: 0 }
    }

    fn generate(&mut self) -> i32 {
        self.state
    }

    fn advance(&mut self) {
        self.state += 1;
    }
}

struct LogisticsOptimizer {
    sequence: SequenceGenerator,
    inventory: i32,
    supply: i32,
}

impl LogisticsOptimizer {
    fn new(sequence: SequenceGenerator) -> Self {
        LogisticsOptimizer {
            sequence,
            inventory: 0,
            supply: 0,
        }
    }

    fn update_inventory(&mut self) {
        self.inventory += self.supply;
        self.supply = self.sequence.generate();
        self.sequence.advance();
    }

    fn optimize(&mut self) {
        self.update_inventory();
        if self.inventory > 100 {
            self.supply = 0;
        } else if self.inventory < 50 {
            self.supply = 50;
        }
    }
}

struct SupplyChainSimulator {
    sequence_generator: SequenceGenerator,
    optimizer: LogisticsOptimizer,
}

impl SupplyChainSimulator {
    fn new() -> Self {
        let sequence_generator = SequenceGenerator::new();
        let optimizer = LogisticsOptimizer::new(sequence_generator);
        SupplyChainSimulator {
            sequence_generator,
            optimizer,
        }
    }

    fn run(&mut self) {
        loop {
            self.optimizer.optimize();
        }
    }
}

fn main() {
    let mut simulator = SupplyChainSimulator::new();
    simulator.run();
}