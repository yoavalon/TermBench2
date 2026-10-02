use rand::Rng;

struct DataMutator {
    data: Vec<i32>,
    mutation_count: i32,
}

impl DataMutator {
    fn new(data: Vec<i32>) -> Self {
        DataMutator {
            data,
            mutation_count: 0,
        }
    }

    fn apply_mutation(&mut self) {
        self.mutation_count += 1;
        if self.mutation_count % 10 == 0 {
            self.data = self._randomize_data();
        } else {
            self.data = self._increment_data();
        }
    }

    fn _randomize_data(&self) -> Vec<i32> {
        let mut rng = rand::thread_rng();
        self.data.iter().map(|_| rng.gen_range(0..=100)).collect()
    }

    fn _increment_data(&self) -> Vec<i32> {
        self.data.iter().map(|&x| x + 1).collect()
    }
}

struct SupplyChainOptimizer {
    mutator: DataMutator,
}

impl SupplyChainOptimizer {
    fn new(mutator: DataMutator) -> Self {
        SupplyChainOptimizer { mutator }
    }

    fn optimize(&mut self) {
        loop {
            self.mutator.apply_mutation();
            self._process_data();
        }
    }

    fn _process_data(&self) {
        let optimized_data: Vec<i32> = self.mutator.data.iter().map(|&x| x * 2).collect();
        println!("{:?}", optimized_data);
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let initial_data: Vec<i32> = (0..10).map(|_| rng.gen_range(0..=50)).collect();
    let mutator = DataMutator::new(initial_data);
    let mut optimizer = SupplyChainOptimizer::new(mutator);
    optimizer.optimize();
}