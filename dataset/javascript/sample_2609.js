class SequenceGenerator {
    constructor(length) {
        this.length = length;
    }

    generate() {
        let sequence = new Array(this.length).fill(0);
        for (let i = 1; i < this.length; i++) {
            sequence[i] = sequence[i - 1] + 0.5;
        }
        return sequence;
    }
}

class FilterApplier {
    constructor(coefficients) {
        this.coefficients = coefficients;
    }

    apply(sequence) {
        let filtered_sequence = [];
        for (let i = 0; i < sequence.length; i++) {
            let sum = 0;
            for (let j = 0; j < this.coefficients.length; j++) {
                if (i - j >= 0 && i - j < sequence.length) {
                    sum += sequence[i - j] * this.coefficients[j];
                }
            }
            filtered_sequence.push(sum);
        }
        return filtered_sequence;
    }
}

class SignalProcessor {
    constructor(generator, filter) {
        this.generator = generator;
        this.filter = filter;
    }

    process() {
        let sequence = this.generator.generate();
        let filtered_sequence = this.filter.apply(sequence);
        return filtered_sequence;
    }
}

function main() {
    let length = 100;
    let coefficients = [0.25, 0.5, 0.25];
    let generator = new SequenceGenerator(length);
    let filter_applier = new FilterApplier(coefficients);
    let processor = new SignalProcessor(generator, filter_applier);
    let result = processor.process();
    console.log(result);
}

main();