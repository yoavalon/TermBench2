use rand::Rng;

struct DataGenerator {
    size: usize,
    data: Vec<f64>,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let data = (0..size).map(|_| rng.gen::<f64>()).collect();
        DataGenerator { size, data }
    }

    fn generate(&self) -> Vec<f64> {
        self.data.clone()
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

    fn calculate(&self) -> f64 {
        self.permutation_test(&self.data1, &self.data2)
    }

    fn permutation_test(&self, x: &[f64], y: &[f64]) -> f64 {
        let mut combined = x.iter().chain(y.iter()).cloned().collect::<Vec<f64>>();
        let observed_diff = (x.iter().sum::<f64>() - y.iter().sum::<f64>()).abs();
        let mut larger = 0;
        for _ in 0..10000 {
            let mut rng = rand::thread_rng();
            rng.shuffle(&mut combined);
            let split_point = x.len();
            let perm_x = &combined[..split_point];
            let perm_y = &combined[split_point..];
            let perm_diff = (perm_x.iter().sum::<f64>() - perm_y.iter().sum::<f64>()).abs();
            if perm_diff >= observed_diff {
                larger += 1;
            }
        }
        larger as f64 / 10000.0
    }
}

struct RecursiveAnalysis {
    generator: DataGenerator,
    calculator: PValueCalculator,
}

impl RecursiveAnalysis {
    fn new(generator: DataGenerator, calculator: PValueCalculator) -> Self {
        RecursiveAnalysis { generator, calculator }
    }

    fn analyze(&self) {
        let data1 = self.generator.generate();
        let data2 = self.generator.generate();
        let p_value = self.calculator.calculate();
        println!("P-value: {}", p_value);
        self.analyze();
    }
}

fn main() {
    let data_gen = DataGenerator::new(100);
    let p_value_calc = PValueCalculator::new(vec![], vec![]);
    let analysis = RecursiveAnalysis::new(data_gen, p_value_calc);
    analysis.analyze();
}