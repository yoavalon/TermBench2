import * as np from 'numpy';

class SequenceGenerator {
    length: number;

    constructor(length: number) {
        this.length = length;
    }

    generate(): number[] {
        let sequence = np.zeros(this.length);
        for (let i = 1; i < this.length; i++) {
            sequence[i] = sequence[i - 1] + 0.5;
        }
        return sequence;
    }
}

class FilterApplier {
    coefficients: number[];

    constructor(coefficients: number[]) {
        this.coefficients = coefficients;
    }

    apply(sequence: number[]): number[] {
        let filtered_sequence = np.convolve(sequence, this.coefficients, 'same');
        return filtered_sequence;
    }
}

class SignalProcessor {
    generator: SequenceGenerator;
    filter: FilterApplier;

    constructor(generator: SequenceGenerator, filter: FilterApplier) {
        this.generator = generator;
        this.filter = filter;
    }

    process(): number[] {
        let sequence = this.generator.generate();
        let filtered_sequence = this.filter.apply(sequence);
        return filtered_sequence;
    }
}

function main() {
    let length = 100;
    let coefficients = np.array([0.25, 0.5, 0.25]);
    let generator = new SequenceGenerator(length);
    let filter_applier = new FilterApplier(coefficients);
    let processor = new SignalProcessor(generator, filter_applier);
    let result = processor.process();
    console.log(result);
}

main();