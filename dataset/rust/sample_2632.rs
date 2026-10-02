struct SequenceGenerator {
    current: i32,
    end: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32, step: i32) -> Self {
        SequenceGenerator {
            current: start,
            end: end,
            step: step,
        }
    }

    fn has_next(&self) -> bool {
        self.current < self.end
    }

    fn next(&mut self) -> Option<i32> {
        if self.has_next() {
            let value = self.current;
            self.current += self.step;
            Some(value)
        } else {
            None
        }
    }
}

struct StateSimulator {
    sequence: SequenceGenerator,
    states: Vec<(i32, f64, f64)>,
}

impl StateSimulator {
    fn new(sequence: SequenceGenerator) -> Self {
        StateSimulator {
            sequence: sequence,
            states: Vec::new(),
        }
    }

    fn simulate(&mut self) {
        while self.sequence.has_next() {
            if let Some(temp) = self.sequence.next() {
                let pressure = (temp as f64) * 1.5;
                let volume = (temp as f64) * 2.0;
                self.states.push((temp, pressure, volume));
            }
        }
    }
}

struct DataProcessor {
    simulator: StateSimulator,
}

impl DataProcessor {
    fn new(simulator: StateSimulator) -> Self {
        DataProcessor {
            simulator: simulator,
        }
    }

    fn process(&self) {
        for state in &self.simulator.states {
            println!("Temperature: {}, Pressure: {}, Volume: {}", state.0, state.1, state.2);
        }
    }
}

fn main() {
    let seq = SequenceGenerator::new(100, 300, 50);
    let mut sim = StateSimulator::new(seq);
    sim.simulate();
    let processor = DataProcessor::new(sim);
    processor.process();
}