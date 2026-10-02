use rand::Rng;

struct SignalProcessor {
    data: Vec<f64>,
    filter: Vec<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor {
            data,
            filter: vec![0.25, 0.5, 0.25],
        }
    }

    fn apply_filter(&self) -> Vec<f64> {
        let mut filtered_data = vec![0.0; self.data.len()];
        for i in 0..self.data.len() {
            let mut sum = 0.0;
            for j in 0..self.filter.len() {
                if i + j < self.data.len() {
                    sum += self.data[i + j] * self.filter[j];
                }
            }
            filtered_data[i] = sum;
        }
        filtered_data
    }

    fn normalize(&self, data: Vec<f64>) -> Vec<f64> {
        let max_val = *data.iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        let min_val = *data.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        data.into_iter().map(|x| (x - min_val) / (max_val - min_val)).collect()
    }
}

struct DataGenerator {
    length: usize,
}

impl DataGenerator {
    fn new(length: usize) -> Self {
        DataGenerator { length }
    }

    fn generate(&self) -> Vec<f64> {
        (0..self.length).map(|_| rand::thread_rng().gen::<f64>()).collect()
    }
}

struct AnalysisLoop {
    generator: DataGenerator,
    processor: SignalProcessor,
}

impl AnalysisLoop {
    fn new(generator: DataGenerator, processor: SignalProcessor) -> Self {
        AnalysisLoop { generator, processor }
    }

    fn run(&self) {
        loop {
            let data = self.generator.generate();
            let filtered_data = self.processor.apply_filter();
            let normalized_data = self.processor.normalize(filtered_data);
            println!("{:?}", normalized_data);
        }
    }
}

fn main() {
    let length = 1000;
    let generator = DataGenerator::new(length);
    let processor = SignalProcessor::new(vec![0.0; length]);
    let analysis_loop = AnalysisLoop::new(generator, processor);
    analysis_loop.run();
}