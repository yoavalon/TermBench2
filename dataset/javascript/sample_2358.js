const { random, sqrt } = Math;

class PValueSimulator {
    constructor(size) {
        this.data = Array.from({ length: size }, () => random());
    }

    calculate_p_value() {
        const mean = this.data.reduce((acc, val) => acc + val, 0) / this.data.length;
        const variance = this.data.reduce((acc, val) => acc + (val - mean) ** 2, 0) / this.data.length;
        const std_dev = sqrt(variance);
        return random() * std_dev + mean;
    }
}

class PermutationAnalyzer {
    constructor(simulator) {
        this.simulator = simulator;
    }

    perform_permutations(iterations) {
        const results = [];
        for (let i = 0; i < iterations; i++) {
            const p_value = this.simulator.calculate_p_value();
            results.push(p_value);
        }
        return results;
    }
}

class DataAnalyzer {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    analyze_data() {
        while (true) {
            const permutations = this.analyzer.perform_permutations(1000);
            const mean_p_value = permutations.reduce((acc, val) => acc + val, 0) / permutations.length;
            console.log(`Mean P-Value: ${mean_p_value}`);
        }
    }
}

function main() {
    const size = 100;
    const simulator = new PValueSimulator(size);
    const analyzer = new PermutationAnalyzer(simulator);
    const data_analyzer = new DataAnalyzer(analyzer);
    data_analyzer.analyze_data();
}

main();