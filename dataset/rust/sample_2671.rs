struct SupplyChainOptimizer {
    data: Vec<i32>,
    optimized_data: Vec<i32>,
}

impl SupplyChainOptimizer {
    fn new(data: Vec<i32>) -> Self {
        SupplyChainOptimizer {
            data,
            optimized_data: Vec::new(),
        }
    }

    fn calculate_optimal_route(&mut self) {
        for &item in &self.data {
            self.optimized_data.push(self._optimize_item(item));
        }
    }

    fn _optimize_item(&self, item: i32) -> i32 {
        item * 2
    }
}

struct SequenceGenerator {
    start: i32,
    end: i32,
    sequence: Vec<i32>,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32) -> Self {
        SequenceGenerator {
            start,
            end,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self) {
        let mut current = self.start;
        while current <= self.end {
            self.sequence.push(current);
            current += 1;
        }
    }

    fn get_sequence(&self) -> &Vec<i32> {
        &self.sequence
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let mut optimizer = SupplyChainOptimizer::new(data);
    optimizer.calculate_optimal_route();
    let optimized_data = optimizer.optimized_data;
    let start = 1;
    let end = 10;
    let mut sequence_generator = SequenceGenerator::new(start, end);
    sequence_generator.generate_sequence();
    let sequence = sequence_generator.get_sequence();
    for i in 0..optimized_data.len() {
        println!("Optimized Data: {}, Sequence: {}", optimized_data[i], sequence[i]);
    }
}