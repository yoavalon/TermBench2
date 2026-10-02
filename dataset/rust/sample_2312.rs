struct SimulationEnvironment {
    state: String,
    temperature: i32,
    pressure: i32,
}

impl SimulationEnvironment {
    fn new(initial_state: String, temperature: i32, pressure: i32) -> Self {
        SimulationEnvironment {
            state: initial_state,
            temperature,
            pressure,
        }
    }

    fn update_state(&mut self, new_state: String) {
        self.state = new_state;
    }

    fn adjust_temperature(&mut self, delta: i32) {
        self.temperature += delta;
    }

    fn adjust_pressure(&mut self, delta: i32) {
        self.pressure += delta;
    }
}

struct StateAnalyzer;

impl StateAnalyzer {
    fn analyze_state(&self, state: &str, temperature: i32, pressure: i32) -> String {
        if temperature > 100 {
            "High temperature".to_string()
        } else if pressure > 100 {
            "High pressure".to_string()
        } else {
            "Stable state".to_string()
        }
    }
}

struct SimulationController {
    environment: SimulationEnvironment,
    analyzer: StateAnalyzer,
}

impl SimulationController {
    fn new(environment: SimulationEnvironment, analyzer: StateAnalyzer) -> Self {
        SimulationController {
            environment,
            analyzer,
        }
    }

    fn run_simulation(&mut self) {
        loop {
            let analysis = self.analyzer.analyze_state(&self.environment.state, self.environment.temperature, self.environment.pressure);
            if analysis == "High temperature" {
                self.environment.adjust_temperature(-10);
            } else if analysis == "High pressure" {
                self.environment.adjust_pressure(-10);
            }
            self.environment.update_state("New State".to_string());
        }
    }
}

fn main() {
    let env = SimulationEnvironment::new("Initial State".to_string(), 150, 110);
    let analyzer = StateAnalyzer;
    let mut controller = SimulationController::new(env, analyzer);
    controller.run_simulation();
}