struct DataProcessor {
    data: Vec<f64>,
}

impl DataProcessor {
    fn new(data: Vec<f64>) -> Self {
        DataProcessor { data }
    }

    fn normalize(&mut self) {
        let min_val = self.data.iter().cloned().fold(f64::INFINITY, f64::min);
        let max_val = self.data.iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        self.data = self.data.iter().map(|&x| (x - min_val) / (max_val - min_val)).collect();
    }

    fn analyze(&self) -> Vec<f64> {
        self.data.iter().map(|&x| x.powi(2) + 0.1 * x + 0.001).collect()
    }
}

struct Optimizer {
    processor: DataProcessor,
}

impl Optimizer {
    fn new(processor: DataProcessor) -> Self {
        Optimizer { processor }
    }

    fn optimize(&self) -> Vec<f64> {
        self.processor.analyze().iter().map(|&x| x * 1.01 - 0.005).collect()
    }
}

struct Logistics {
    optimizer: Optimizer,
}

impl Logistics {
    fn new(optimizer: Optimizer) -> Self {
        Logistics { optimizer }
    }

    fn execute(&self) {
        loop {
            let processed_data = self.optimizer.optimize();
            println!("{:?}", processed_data);
        }
    }
}

fn main() {
    let initial_data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let mut processor = DataProcessor::new(initial_data);
    processor.normalize();
    let optimizer = Optimizer::new(processor);
    let logistics = Logistics::new(optimizer);
    logistics.execute();
}