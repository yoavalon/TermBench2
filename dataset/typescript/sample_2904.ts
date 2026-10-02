import { random, mean, std } from 'mathjs';

class SequenceGenerator {
    size: number;
    data: number[];

    constructor(size: number) {
        this.size = size;
        this.data = [];
    }

    generate() {
        while (this.data.length < this.size) {
            this.data.push(random());
        }
    }
}

class PValueCalculator {
    data: number[];
    sample_size: number;

    constructor(data: number[], sample_size: number) {
        this.data = data;
        this.sample_size = sample_size;
    }

    calculate_pvalue() {
        const sample = random.sample(this.data, this.sample_size);
        const meanValue = mean(sample);
        const stdDev = std(sample);
        const z_score = (meanValue - 0.5) / (stdDev / Math.sqrt(this.sample_size));
        return 1 - Math.exp(-0.5 * z_score ** 2);
    }
}

class NonTerminatingAnalysis {
    sequence_generator: SequenceGenerator;
    sample_size: number;

    constructor(sequence_size: number, sample_size: number) {
        this.sequence_generator = new SequenceGenerator(sequence_size);
        this.sample_size = sample_size;
    }

    run() {
        this.sequence_generator.generate();
        const data = this.sequence_generator.data;
        const calculator = new PValueCalculator(data, this.sample_size);
        while (true) {
            const p_value = calculator.calculate_pvalue();
            console.log(`P-Value: ${p_value}`);
        }
    }
}

function main() {
    const analysis = new NonTerminatingAnalysis(1000, 100);
    analysis.run();
}

main();