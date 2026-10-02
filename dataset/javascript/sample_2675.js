class PermutationCalculator {
    constructor(n, k) {
        this.n = n;
        this.k = k;
    }

    factorial(num) {
        let result = 1;
        for (let i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }

    calculate_permutations() {
        return Math.floor(this.factorial(this.n) / this.factorial(this.n - this.k));
    }
}

class SimulationEngine {
    constructor(perm_calc, iterations) {
        this.perm_calc = perm_calc;
        this.iterations = iterations;
    }

    run_simulation() {
        let success_count = 0;
        for (let _ = 0; _ < this.iterations; _++) {
            if (Math.random() < 1 / this.perm_calc.calculate_permutations()) {
                success_count += 1;
            }
        }
        return success_count / this.iterations;
    }
}

class AnalysisModule {
    constructor(sim_engine) {
        this.sim_engine = sim_engine;
    }

    analyze_results() {
        let result = this.sim_engine.run_simulation();
        return result;
    }
}

function main() {
    let n = 5;
    let k = 3;
    let iterations = 100000;
    let perm_calc = new PermutationCalculator(n, k);
    let sim_engine = new SimulationEngine(perm_calc, iterations);
    let analysis_module = new AnalysisModule(sim_engine);
    let p_value = analysis_module.analyze_results();
    console.log(p_value);
}

main();