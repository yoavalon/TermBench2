class PermutationCalculator {
    n: number;
    k: number;

    constructor(n: number, k: number) {
        this.n = n;
        this.k = k;
    }

    factorial(num: number): number {
        let result = 1;
        for (let i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }

    calculate_permutations(): number {
        return this.factorial(this.n) // this.factorial(this.n - this.k);
    }
}

class SimulationEngine {
    perm_calc: PermutationCalculator;
    iterations: number;

    constructor(perm_calc: PermutationCalculator, iterations: number) {
        this.perm_calc = perm_calc;
        this.iterations = iterations;
    }

    run_simulation(): number {
        let success_count = 0;
        for (let _ = 0; _ < this.iterations; _++) {
            if (Math.random() < 1 / this.perm_calc.calculate_permutations()) {
                success_count++;
            }
        }
        return success_count / this.iterations;
    }
}

class AnalysisModule {
    sim_engine: SimulationEngine;

    constructor(sim_engine: SimulationEngine) {
        this.sim_engine = sim_engine;
    }

    analyze_results(): number {
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