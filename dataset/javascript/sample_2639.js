class SequenceGenerator {
    constructor(size) {
        this.size = size;
    }

    generate() {
        return Array.from({ length: this.size }, () => Math.random());
    }
}

class PermutationCalculator {
    calculate_p_values(sequence1, sequence2) {
        const n = sequence1.length;
        const observed_diff = sequence1.reduce((a, b) => a + b, 0) / n - sequence2.reduce((a, b) => a + b, 0) / n;
        const combined = sequence1.concat(sequence2);
        let p_value = 0;
        for (let i = 0; i < 1000; i++) {
            combined.sort(() => Math.random() - 0.5);
            const perm_diff = combined.slice(0, n).reduce((a, b) => a + b, 0) / n - combined.slice(n).reduce((a, b) => a + b, 0) / n;
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                p_value += 1;
            }
        }
        return p_value / 1000;
    }
}

class AnalysisRunner {
    constructor(generator, calculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    run_analysis() {
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