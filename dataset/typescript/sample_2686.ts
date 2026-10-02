import * as math from 'mathjs';
import * as _ from 'lodash';

class SequenceGenerator {
    size: number;
    data: number[];

    constructor(size: number) {
        this.size = size;
        this.data = math.randomMatrix([size, 1]).flatten();
    }

    generate_sequence(): number[] {
        return this.data;
    }
}

class PValueCalculator {
    sequence1: number[];
    sequence2: number[];

    constructor(sequence1: number[], sequence2: number[]) {
        this.sequence1 = sequence1;
        this.sequence2 = sequence2;
    }

    calculate_p_value(): number {
        const diff = math.mean(this.sequence1) - math.mean(this.sequence2);
        const bootstrap_samples: number[] = [];
        for (let i = 0; i < 1000; i++) {
            const combined = this.sequence1.concat(this.sequence2);
            _.shuffle(combined);
            const new_mean_diff = math.mean(combined.slice(0, this.sequence1.length)) - math.mean(combined.slice(this.sequence1.length));
            bootstrap_samples.push(new_mean_diff);
        }
        const bootstrap_samples_array = math.array(bootstrap_samples);
        const p_value = (math.sum(math.abs(bootstrap_samples_array).greaterEqual(math.abs(diff))) + 1) / (bootstrap_samples_array.size() + 1);
        return p_value;
    }
}

class AnalysisRunner {
    sequence_generator1: SequenceGenerator;
    sequence_generator2: SequenceGenerator;

    constructor(sequence_generator1: SequenceGenerator, sequence_generator2: SequenceGenerator) {
        this.sequence_generator1 = sequence_generator1;
        this.sequence_generator2 = sequence_generator2;
    }

    run_analysis(): number {
        const seq1 = this.sequence_generator1.generate_sequence();
        const seq2 = this.sequence_generator2.generate_sequence();
        const p_value_calculator = new PValueCalculator(seq1, seq2);
        const p_value = p_value_calculator.calculate_p_value();
        return p_value;
    }
}

function main() {
    const size1 = 100;
    const size2 = 100;
    const seq_gen1 = new SequenceGenerator(size1);
    const seq_gen2 = new SequenceGenerator(size2);
    const analysis_runner = new AnalysisRunner(seq_gen1, seq_gen2);
    const result = analysis_runner.run_analysis();
    console.log(result);
}

main();