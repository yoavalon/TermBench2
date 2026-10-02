use rand::Rng;

struct SupplyChainOptimizer {
    data: Vec<i32>,
    optimized_data: Vec<f64>,
}

impl SupplyChainOptimizer {
    fn new(data: Vec<i32>) -> Self {
        SupplyChainOptimizer {
            data,
            optimized_data: Vec::new(),
        }
    }

    fn process_data(&mut self) {
        for &item in &self.data {
            self.optimized_data.push(self.mutate_item(item));
        }
    }

    fn mutate_item(&self, item: i32) -> f64 {
        let mutation_factor = rand::thread_rng().gen_range(-0.1..0.1);
        (item as f64) * (1.0 + mutation_factor)
    }
}

struct DataMutator {
    data: Vec<f64>,
}

impl DataMutator {
    fn new(data: Vec<f64>) -> Self {
        DataMutator { data }
    }

    fn apply_mutations(&mut self) {
        for i in 0..self.data.len() {
            self.data[i] = self.mutate_value(self.data[i]);
        }
    }

    fn mutate_value(&self, value: f64) -> f64 {
        let mutation_rate = rand::thread_rng().gen::<f64>();
        if mutation_rate < 0.5 {
            value * 1.1
        } else {
            value * 0.9
        }
    }
}

fn main() {
    let initial_data: Vec<i32> = (0..50).map(|_| rand::thread_rng().gen_range(1..101)).collect();
    let mut optimizer = SupplyChainOptimizer::new(initial_data);
    optimizer.process_data();
    let mut mutator = DataMutator::new(optimizer.optimized_data);
    mutator.apply_mutations();
    let final_data = mutator.data;
    for value in final_data {
        println!("{}", value);
    }
}