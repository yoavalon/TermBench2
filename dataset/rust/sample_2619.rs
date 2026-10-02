struct SequenceGenerator {
    current: i32,
    stop: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, stop: i32, step: i32) -> Self {
        SequenceGenerator {
            current: start,
            stop: stop,
            step: step,
        }
    }

    fn generate(&mut self) -> Vec<i32> {
        let mut result = Vec::new();
        while self.current < self.stop {
            result.push(self.current);
            self.current += self.step;
        }
        result
    }
}

struct ThermodynamicSimulator {
    sequence: SequenceGenerator,
    temperature: f64,
}

impl ThermodynamicSimulator {
    fn new(sequence: SequenceGenerator) -> Self {
        ThermodynamicSimulator {
            sequence: sequence,
            temperature: 300.0,
        }
    }

    fn simulate(&mut self) -> Vec<f64> {
        let mut result = Vec::new();
        for value in self.sequence.generate() {
            self.temperature += value as f64 * 0.1;
            result.push(self.temperature);
        }
        result
    }
}

struct DataCollector {
    simulator: ThermodynamicSimulator,
    data: Vec<f64>,
}

impl DataCollector {
    fn new(simulator: ThermodynamicSimulator) -> Self {
        DataCollector {
            simulator: simulator,
            data: Vec::new(),
        }
    }

    fn collect(&mut self) -> Vec<f64> {
        self.data = self.simulator.simulate();
        self.data.clone()
    }
}

fn main() {
    let start = 0;
    let stop = 100;
    let step = 5;
    let sequence = SequenceGenerator::new(start, stop, step);
    let mut simulator = ThermodynamicSimulator::new(sequence);
    let mut collector = DataCollector::new(simulator);
    let result = collector.collect();
    println!("{:?}", result);
}