use rand::Rng;

struct PermutationCalculator {
    n: u32,
    k: u32,
}

impl PermutationCalculator {
    fn new(n: u32, k: u32) -> Self {
        PermutationCalculator { n, k }
    }

    fn factorial(&self, num: u32) -> u32 {
        (2..=num).product()
    }

    fn calculate_permutations(&self) -> u32 {
        self.factorial(self.n) / self.factorial(self.n - self.k)
    }
}

struct SimulationEngine {
    perm_calc: PermutationCalculator,
    iterations: u32,
}

impl SimulationEngine {
    fn new(perm_calc: PermutationCalculator, iterations: u32) -> Self {
        SimulationEngine { perm_calc, iterations }
    }

    fn run_simulation(&self) -> f64 {
        let mut success_count = 0;
        let mut rng = rand::thread_rng();
        for _ in 0..self.iterations {
            if rng.gen::<f64>() < 1.0 / self.perm_calc.calculate_permutations() as f64 {
                success_count += 1;
            }
        }
        success_count as f64 / self.iterations as f64
    }
}

struct AnalysisModule {
    sim_engine: SimulationEngine,
}

impl AnalysisModule {
    fn new(sim_engine: SimulationEngine) -> Self {
        AnalysisModule { sim_engine }
    }

    fn analyze_results(&self) -> f64 {
        self.sim_engine.run_simulation()
    }
}

fn main() {
    let n = 5;
    let k = 3;
    let iterations = 100000;
    let perm_calc = PermutationCalculator::new(n, k);
    let sim_engine = SimulationEngine::new(perm_calc, iterations);
    let analysis_module = AnalysisModule::new(sim_engine);
    let p_value = analysis_module.analyze_results();
    println!("{}", p_value);
}