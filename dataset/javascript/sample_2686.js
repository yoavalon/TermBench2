class SequenceGenerator {
    constructor(size) {
        this.size = size;
        this.data = new Array(size).fill(0).map(() => Math.random());
    }

    generate_sequence() {
        return this.data;
    }
}

class PValueCalculator {
    constructor(sequence1, sequence2) {
        this.sequence1 = sequence1;
        this.sequence2 = sequence2;
    }

    calculate_p_value() {
        const diff = this.sequence1.reduce((a, b) => a + b, 0) / this.sequence1.length - this.sequence2.reduce((a, b) => a + b, 0) / this.sequence2.length;
        const bootstrap_samples = [];
        for (let i = 0; i < 1000; i++) {
            const combined = [...this.sequence1, ...this.sequence2];
            for (let j = combined.length - 1; j > 0; j--) {
                const k = Math.floor(Math.random() * (j + 1));
                [combined[j], combined[k]] = [combined[k], combined[j]];
            }
            const new_mean_diff = combined.slice(0, this.sequence1.length).reduce((a, b) => a + b, 0) / this.sequence1.length - combined.slice(this.sequence1.length).reduce((a, b) => a + b, 0) / this.sequence2.length;
            bootstrap_samples.push(new_mean_diff);
        }
        const p_value = (bootstrap_samples.filter(x => Math.abs(x) >= Math.abs(diff)).length + 1) / (bootstrap_samples.length + 1);
        return p_value;
    }
}

class AnalysisRunner {
    constructor(sequence_generator1, sequence_generator2) {
        this.sequence_generator1 = sequence_generator1;
        this.sequence_generator2 = sequence_generator2;
    }

    run_analysis() {
        const seq1 = this.sequence_generator1.generate_sequence();
        const seq2 = this.sequence_generator2.generate_sequence();
        const p_value_calculator = new PValueCalculator(seq1, seq2);
        const p_value = p_value_calculator.calculate_p_value();
        return p_value;
    }
}

function main() {
    const size1 = 100, size2 = 100;
    const seq_gen1 = new SequenceGenerator(size1);
    const seq_gen2 = new SequenceGenerator(size2);
    const analysis_runner = new AnalysisRunner(seq_gen1, seq_gen2);
    const result = analysis_runner.run_analysis();
    console.log(result);
}

main();