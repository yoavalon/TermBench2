import * as math from 'mathjs';
import * as random from 'random-js';

class PValueSimulator {
    data: number[];

    constructor(size: number) {
        this.data = Array.from({ length: size }, () => random.random());
    }

    calculate_p_value(): number {
        const mean = this.data.reduce((acc, val) => acc + val, 0) / this.data.length;
        const variance = this.data.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / this.data.length;
        const std_dev = math.sqrt(variance);
        return random.gauss(mean, std_dev);
    }
}

class PermutationAnalyzer {
    simulator: PValueSimulator;

    constructor(simulator: PValueSimulator) {
        this.simulator = simulator;
    }

    perform_permutations(iterations: number): number[] {
        const results: number[] = [];
        for (let i = 0; i < iterations; i++) {
            const p_value = this.simulator.calculate_p_value();
            results.push(p_value);
        }
        return results;
    }
}

class DataAnalyzer {
    analyzer: PermutationAnalyzer;

    constructor(analyzer: PermutationAnalyzer) {
        this.analyzer = analyzer;
    }

    analyze_data(): void {
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