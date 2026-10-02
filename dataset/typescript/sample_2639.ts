import * as random from 'mathjs';
import * as np from 'mathjs';

class SequenceGenerator {
    size: number;

    constructor(size: number) {
        this.size = size;
    }

    generate(): number[] {
        return Array.from({ length: this.size }, () => random.random());
    }
}

class PermutationCalculator {
    calculate_p_values(sequence1: number[], sequence2: number[]): number {
        const n = sequence1.length;
        const observed_diff = np.mean(sequence1) - np.mean(sequence2);
        const combined = [...sequence1, ...sequence2];
        let p_value = 0;
        for (let i = 0; i < 1000; i++) {
            random.shuffle(combined);
            const perm_diff = np.mean(combined.slice(0, n)) - np.mean(combined.slice(n));
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                p_value += 1;
            }
        }
        return p_value / 1000;
    }
}

class AnalysisRunner {
    generator: SequenceGenerator;
    calculator: PermutationCalculator;

    constructor(generator: SequenceGenerator, calculator: PermutationCalculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    run_analysis(): number {
        const seq1 = this.generator.generate();
        const seq2 = this.generator.generate();
        const p_value = this.calculator.calculate_p_values(seq1, seq2);
        return p_value;
    }
}

function main() {
    const size = 30;
    const generator = new SequenceGenerator(size);
    const calculator = new PermutationCalculator();
    const runner = new AnalysisRunner(generator, calculator);
    const result = runner.run_analysis();
    console.log(result);
}

main();