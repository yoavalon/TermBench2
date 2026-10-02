struct SequenceGenerator {
    value: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(initial_value: i32, step: i32) -> Self {
        SequenceGenerator {
            value: initial_value,
            step: step,
        }
    }

    fn next(&mut self) -> i32 {
        self.value += self.step;
        self.value
    }
}

struct ThermodynamicSimulator {
    sequence: SequenceGenerator,
    temperature: f64,
    pressure: f64,
}

impl ThermodynamicSimulator {
    fn new(sequence: SequenceGenerator) -> Self {
        ThermodynamicSimulator {
            sequence: sequence,
            temperature: 0.0,
            pressure: 1.0,
        }
    }

    fn update_state(&mut self) {
        self.temperature += self.sequence.next() as f64 / 100.0;
        self.pressure += self.sequence.next() as f64 / 1000.0;
    }

    fn get_state(&self) -> (f64, f64) {
        (self.temperature, self.pressure)
    }
}

struct DataCollector {
    simulator: ThermodynamicSimulator,
    data: Vec<(f64, f64)>,
}

impl DataCollector {
    fn new(simulator: ThermodynamicSimulator) -> Self {
        DataCollector {
            simulator: simulator,
            data: Vec::new(),
        }
    }

    fn collect(&mut self) {
        let (temp, press) = self.simulator.get_state();
        self.data.push((temp, press));
    }

    fn display(&self) {
        for entry in &self.data {
            println!("{:?}", entry);
        }
    }
}

fn main() {
    let seq = SequenceGenerator::new(1, 1);
    let sim = ThermodynamicSimulator::new(seq);
    let mut collector = DataCollector::new(sim);
    loop {
        collector.simulator.update_state();
        collector.collect();
        collector.display();
    }
}