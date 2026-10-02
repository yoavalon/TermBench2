use std::f64::consts::E;

struct SequenceSimulator {
    a: f64,
    b: f64,
    n: usize,
    sequence: Vec<f64>,
}

impl SequenceSimulator {
    fn new(a: f64, b: f64, n: usize) -> Self {
        SequenceSimulator {
            a,
            b,
            n,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self) {
        for i in 0..self.n {
            let value = self.a + i as f64 * self.b;
            self.sequence.push(value);
        }
    }

    fn calculate_thermodynamic_states(&self) -> Vec<f64> {
        self.sequence.iter().map(|&value| E.powf(-value)).collect()
    }
}

struct DataAnalyzer {
    data: Vec<f64>,
}

impl DataAnalyzer {
    fn new(data: Vec<f64>) -> Self {
        DataAnalyzer { data }
    }

    fn average(&self) -> f64 {
        self.data.iter().sum::<f64>() / self.data.len() as f64
    }

    fn max_value(&self) -> f64 {
        *self.data.iter().max_by(|x, y| x.partial_cmp(y).unwrap()).unwrap()
    }

    fn min_value(&self) -> f64 {
        *self.data.iter().min_by(|x, y| x.partial_cmp(y).unwrap()).unwrap()
    }
}

fn main() {
    let a = 0.0;
    let b = 0.1;
    let n = 100;
    let mut simulator = SequenceSimulator::new(a, b, n);
    simulator.generate_sequence();
    let states = simulator.calculate_thermodynamic_states();
    let analyzer = DataAnalyzer::new(states);
    println!("Average State: {}", analyzer.average());
    println!("Max State: {}", analyzer.max_value());
    println!("Min State: {}", analyzer.min_value());
}