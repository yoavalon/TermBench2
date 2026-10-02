struct SequenceSimulator {
    a: i32,
    b: i32,
    n: i32,
}

impl SequenceSimulator {
    fn new(a: i32, b: i32, n: i32) -> Self {
        SequenceSimulator { a, b, n }
    }

    fn generate_sequence(&self) -> Vec<i32> {
        let mut sequence = Vec::new();
        let mut current = self.a;
        for _ in 0..self.n {
            sequence.push(current);
            current = self.b * current;
        }
        sequence
    }

    fn analyze_sequence(&self, sequence: Vec<i32>) -> std::collections::HashMap<&'static str, f64> {
        let sum: i32 = sequence.iter().sum();
        let max = sequence.iter().max().unwrap();
        let min = sequence.iter().min().unwrap();
        let mean = sum as f64 / sequence.len() as f64;
        let mut analysis = std::collections::HashMap::new();
        analysis.insert("sum", sum as f64);
        analysis.insert("max", *max as f64);
        analysis.insert("min", *min as f64);
        analysis.insert("mean", mean);
        analysis
    }
}

struct ThermodynamicState {
    temperature: i32,
    pressure: i32,
}

impl ThermodynamicState {
    fn new(temperature: i32, pressure: i32) -> Self {
        ThermodynamicState { temperature, pressure }
    }

    fn update_state(&mut self, sequence_analysis: &std::collections::HashMap<&'static str, f64>) {
        self.temperature = sequence_analysis["max"] as i32;
        self.pressure = sequence_analysis["min"] as i32;
    }
}

fn main() {
    let sim = SequenceSimulator::new(2, 3, 10);
    let seq = sim.generate_sequence();
    let analysis = sim.analyze_sequence(seq);
    let mut state = ThermodynamicState::new(300, 1);
    state.update_state(&analysis);
    println!("Final Temperature: {}, Final Pressure: {}", state.temperature, state.pressure);
}