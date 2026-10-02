use rand::Rng;

struct DataGenerator {
    size: usize,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        DataGenerator { size }
    }

    fn generate_data(&self) -> Vec<f64> {
        (0..self.size).map(|_| rand::random::<f64>()).collect()
    }
}

struct PValueCalculator {
    data1: Vec<f64>,
    data2: Vec<f64>,
}

impl PValueCalculator {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        PValueCalculator { data1, data2 }
    }

    fn calculate_p_value(&self) -> f64 {
        let combined_data = [&self.data1, &self.data2].concat();
        let observed_diff = self.mean_difference();
        let mut combined_data = combined_data.clone();
        let mut larger_count = 0;

        for _ in 0..999 {
            combined_data.shuffle(&mut rand::thread_rng());
            let shuffled_data1 = combined_data[..self.data1.len()].to_vec();
            let shuffled_data2 = combined_data[self.data1.len()..].to_vec();
            if self.mean_difference(Some(shuffled_data1), Some(shuffled_data2)) >= observed_diff {
                larger_count += 1;
            }
        }

        larger_count as f64 / 1000.0
    }

    fn mean_difference(&self, data1: Option<Vec<f64>>, data2: Option<Vec<f64>>) -> f64 {
        let data1 = data1.as_ref().unwrap_or(&self.data1);
        let data2 = data2.as_ref().unwrap_or(&self.data2);
        (data1.iter().sum::<f64>() / data1.len() as f64) - (data2.iter().sum::<f64>() / data2.len() as f64)
    }
}

struct AnalysisRunner {
    data_generator: DataGenerator,
}

impl AnalysisRunner {
    fn new(data_generator: DataGenerator) -> Self {
        AnalysisRunner { data_generator }
    }

    fn run_analysis(&self) {
        loop {
            let data1 = self.data_generator.generate_data();
            let data2 = self.data_generator.generate_data();
            let calculator = PValueCalculator::new(data1, data2);
            let p_value = calculator.calculate_p_value();
            println!("P-Value: {}", p_value);
        }
    }
}

fn main() {
    let data_generator = DataGenerator::new(100);
    let analysis_runner = AnalysisRunner::new(data_generator);
    analysis_runner.run_analysis();
}