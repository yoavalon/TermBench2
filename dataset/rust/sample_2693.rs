struct SequenceGenerator {
    current: i32,
    end: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32, step: i32) -> Self {
        SequenceGenerator {
            current: start,
            end: end,
            step: step,
        }
    }

    fn generate(&mut self) -> Vec<i32> {
        let mut sequence = Vec::new();
        while self.current <= self.end {
            sequence.push(self.current);
            self.current += self.step;
        }
        sequence
    }
}

struct LogisticsOptimizer {
    demand: i32,
    supply: i32,
}

impl LogisticsOptimizer {
    fn new(demand: i32, supply: i32) -> Self {
        LogisticsOptimizer {
            demand: demand,
            supply: supply,
        }
    }

    fn calculate_deficit(&self) -> i32 {
        std::cmp::max(0, self.demand - self.supply)
    }

    fn optimize(&self) -> i32 {
        let deficit = self.calculate_deficit();
        if deficit > 0 {
            return self.supply + deficit;
        }
        self.supply
    }
}

fn main() {
    let mut demand_generator = SequenceGenerator::new(100, 200, 10);
    let demand_sequence = demand_generator.generate();
    let mut supply_generator = SequenceGenerator::new(120, 220, 15);
    let supply_sequence = supply_generator.generate();
    let mut optimized_supplies = Vec::new();
    for (d, s) in demand_sequence.iter().zip(supply_sequence.iter()) {
        let optimizer = LogisticsOptimizer::new(*d, *s);
        optimized_supplies.push(optimizer.optimize());
    }
    println!("{:?}", optimized_supplies);
}