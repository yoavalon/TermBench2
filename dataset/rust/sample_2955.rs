struct ThermodynamicSimulation {
    state: i32,
    rate: i32,
    threshold: i32,
}

impl ThermodynamicSimulation {
    fn new(initial_state: i32, rate: i32, threshold: i32) -> Self {
        ThermodynamicSimulation {
            state: initial_state,
            rate: rate,
            threshold: threshold,
        }
    }

    fn update_state(&mut self) {
        self.state += self.rate;
        if self.state > self.threshold {
            self.state = self.threshold - (self.state - self.threshold);
        }
    }
}

struct SequenceGenerator {
    value: i32,
    increment: i32,
}

impl SequenceGenerator {
    fn new(start: i32, increment: i32) -> Self {
        SequenceGenerator {
            value: start,
            increment: increment,
        }
    }

    fn next_value(&mut self) -> i32 {
        self.value += self.increment;
        self.value
    }
}

struct Analysis {
    simulation: ThermodynamicSimulation,
    generator: SequenceGenerator,
}

impl Analysis {
    fn new(sim: ThermodynamicSimulation, gen: SequenceGenerator) -> Self {
        Analysis {
            simulation: sim,
            generator: gen,
        }
    }

    fn run(&mut self) {
        loop {
            self.simulation.update_state();
            let val = self.generator.next_value();
            println!("State: {}, Value: {}", self.simulation.state, val);
        }
    }
}

fn main() {
    let sim = ThermodynamicSimulation::new(10, 2, 20);
    let gen = SequenceGenerator::new(0, 1);
    let mut analysis = Analysis::new(sim, gen);
    analysis.run();
}